//практическое задание 2 (задание B и D)
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QGroupBox>
#include <QMessageBox>
#include <QProgressBar>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QVector>
#include <QMap>


// Одна запись о расходе — хранит все данные одной траты
struct Expense {
    QString category, description, date; // категория, описание, дата
    double amount;                        // сумма
};

// Категории объявлены один раз — используются в форме, фильтре и прогресс-барах
const QStringList CATS = {
    "Еда","Транспорт","Жильё","Развлечения","Здоровье","Одежда","Другое"
};


// Q_OBJECT обязателен — без него connect() не работает для наших методов
class MainWindow : public QWidget
{
    Q_OBJECT

    //конструктор
public:
    explicit MainWindow(QWidget *parent = nullptr) : QWidget(parent), budget(50000.0)//экспилисит - защита от случайных преобразований типов
    {
        setWindowTitle("Финансовый трекер");
        resize(800, 600);
        buildUI();//строим весь интерфейс в отдельном методе чтобы конструктор не был огромным.
        updateSummary();//сразу рисуем итоги. Пока всё нули, но метки появятся на экране.
    }

private slots:

    // Читаем форму → создаём Expense → добавляем в вектор → обновляем UI
    void addExpense()
    {          //описание
        QString desc = descEdit->text().trimmed(); // trimmed() убирает пробелы по краям
        //проверка на пустую строку
        if (desc.isEmpty()) {
            QMessageBox::warning(this, "Ошибка", "Введите описание.");
            descEdit->setFocus();// ставит курсор обратно в поле описания. Чтобы пользователь сразу мог начать вводить без лишнего клика мышкой.
            return;
        }
        expenses.append({ catCombo->currentText(), desc,
                         QDate::currentDate().toString("dd.MM.yyyy"),
                         amountSpin->value() });//добавит новый элемент в конец списка
        descEdit->clear();
        amountSpin->setValue(0.01);//сбрасывает сумму на минимальное значение
        descEdit->setFocus();
        refreshTable();
        updateSummary();
    }

    // Ищем запись в векторе по дате+описанию → удаляем → обновляем UI
    void deleteSelected()
    {
        int row = table->currentRow(); // -1 если ничего не выбрано ,номер строки которую выбрал пользователь
        if (row < 0) { QMessageBox::information(this, "Удаление", "Выберите строку."); return; }

        QString date = table->item(row, 0)->text();
        QString desc = table->item(row, 2)->text();
        for (int i = 0; i < expenses.size(); ++i) {
            if (expenses[i].date == date && expenses[i].description == desc) {
                expenses.removeAt(i); break;
            }
        }
        refreshTable();
        updateSummary();
    }

    // Пересчитываем итоги из вектора и обновляем все метки и прогресс-бары
    void updateSummary()
    {
        double total = 0;
        for (const auto &e : expenses) total += e.amount;
        double remain = budget - total;//остаток на покупки разные

        totalLabel->setText("Потрачено: " + QString::number(total, 'f', 2) + " ₽");
        remainLabel->setText("Остаток: " + QString::number(remain, 'f', 2) + " ₽");

        // Цвет остатка: красный / оранжевый / зелёный
        QString color = (remain < 0) ? "#e74c3c" : (remain < budget * 0.2) ? "#f39c12" : "#27ae60";
        remainLabel->setStyleSheet("font-size:14px; font-weight:bold; color:" + color + ";");

        // Задание B: считаем сумму по каждой категории и обновляем прогресс-бары
        QMap<QString, double> totals; // словарь: категория → сумма
        for (const auto &e : expenses) totals[e.category] += e.amount;

        for (const QString &cat : CATS) {
            double val = totals.value(cat, 0); // 0 если категория не тратилась
            int pct = (total > 0) ? static_cast<int>(val / total * 100) : 0;//считаем процент этой категории от общей суммы
            catBars[cat]->setValue(pct);//заполнение прогресс бара
            catLabels[cat]->setText(cat + ": " + QString::number(val, 'f', 2) + " ₽");
        }
    }

    // Задание D: сохраняем все расходы в CSV файл (открывается в Excel)
    void exportCSV()
    {
        if (expenses.isEmpty()) { QMessageBox::information(this, "Экспорт", "Нет данных."); return; }

        // Диалог "Сохранить как" — возвращает путь или пустую строку если отмена
        QString path = QFileDialog::getSaveFileName(this, "Сохранить CSV", "расходы.csv", "CSV (*.csv)");
        if (path.isEmpty()) return;

        QFile f(path);
        if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл."); return;
        }
        QTextStream out(&f);//создание удобногго потока для чтения
        out.setEncoding(QStringConverter::Utf8); // UTF-8 чтобы кириллица читалась в Excel
        out << "Дата;Категория;Описание;Сумма\n";
        for (const auto &e : expenses)
            out << e.date << ";" << e.category << ";" << e.description << ";"
                << QString::number(e.amount, 'f', 2) << "\n";
        f.close();
        QMessageBox::information(this, "Готово", "Файл сохранён:\n" + path);
    }

private:

    // Очищаем таблицу и рисуем заново из вектора expenses с учётом фильтра
    void refreshTable()
    {
        QString filter = filterCombo->currentText();
        table->setRowCount(0); // удалить все строки
        for (const auto &e : expenses) {
            if (filter != "Все" && e.category != filter) continue; // пропустить если не та категория
            int row = table->rowCount();
            table->insertRow(row);
            table->setItem(row, 0, new QTableWidgetItem(e.date));
            table->setItem(row, 1, new QTableWidgetItem(e.category));
            table->setItem(row, 2, new QTableWidgetItem(e.description));
            auto *item = new QTableWidgetItem(QString::number(e.amount, 'f', 2) + " ₽");
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter); // числа по правому краю
            table->setItem(row, 3, item);
        }
    }

    void buildUI()
    {
        auto *main = new QVBoxLayout(this); // главная колонка — всё складывается сверху вниз

        // --- Форма ввода нового расхода ---
        auto *inputGroup = new QGroupBox("Новый расход");
        auto *inputRow   = new QHBoxLayout();
        catCombo   = new QComboBox();      catCombo->addItems(CATS); catCombo->setMinimumWidth(110);
        descEdit   = new QLineEdit();      descEdit->setPlaceholderText("Описание...");
        amountSpin = new QDoubleSpinBox(); amountSpin->setRange(0.01, 999999); amountSpin->setPrefix("₽ "); amountSpin->setDecimals(2);
        auto *addBtn = new QPushButton("Добавить");
        addBtn->setStyleSheet("background:#27ae60; color:white; font-weight:bold; padding:6px 14px; border-radius:4px;");
        inputRow->addWidget(new QLabel("Категория:")); inputRow->addWidget(catCombo);
        inputRow->addWidget(new QLabel("Описание:"));  inputRow->addWidget(descEdit, 1);
        inputRow->addWidget(new QLabel("Сумма:"));     inputRow->addWidget(amountSpin);
        inputRow->addWidget(addBtn);
        inputGroup->setLayout(inputRow);
        main->addWidget(inputGroup);

        // --- Таблица расходов ---
        table = new QTableWidget();
        table->setColumnCount(4);
        table->setHorizontalHeaderLabels({"Дата","Категория","Описание","Сумма"});
        table->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch); // столбец "Описание" растягивается
        table->horizontalHeader()->setStretchLastSection(true);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);    // выделяется вся строка
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);     // запрет редактирования в таблице
        table->setAlternatingRowColors(true);                          // чередующиеся цвета строк
        main->addWidget(table, 1); // 1 = таблица занимает всё свободное место

        // --- Фильтр и кнопки ---
        auto *ctrlRow = new QHBoxLayout();
        filterCombo = new QComboBox(); filterCombo->addItem("Все"); filterCombo->addItems(CATS);
        auto *delBtn    = new QPushButton("Удалить выбранное");
        auto *exportBtn = new QPushButton("Экспорт CSV");
        delBtn->setStyleSheet("background:#e74c3c; color:white; padding:6px 12px; border-radius:4px;");
        exportBtn->setStyleSheet("background:#3498db; color:white; padding:6px 12px; border-radius:4px;");
        ctrlRow->addWidget(new QLabel("Фильтр:")); ctrlRow->addWidget(filterCombo);
        ctrlRow->addStretch(); // пружина — прижимает кнопки вправо
        ctrlRow->addWidget(exportBtn); ctrlRow->addWidget(delBtn);
        main->addLayout(ctrlRow);

        // --- Панель итогов ---
        auto *sumGroup = new QGroupBox("Итоги");
        auto *sumRow   = new QHBoxLayout();
        totalLabel  = new QLabel("Потрачено: 0.00 ₽");
        budgetLabel = new QLabel("Бюджет: " + QString::number(budget, 'f', 2) + " ₽");
        remainLabel = new QLabel("Остаток: 0.00 ₽");
        totalLabel->setStyleSheet("font-size:14px;");
        budgetLabel->setStyleSheet("font-size:14px;");
        sumRow->addWidget(totalLabel); sumRow->addWidget(budgetLabel); sumRow->addWidget(remainLabel);
        sumGroup->setLayout(sumRow);
        main->addWidget(sumGroup);

        // --- Задание B: прогресс-бары — создаём по одному на каждую категорию ---
        // Храним в QMap чтобы потом найти нужный по имени категории: catBars["Еда"]
        auto *catGroup  = new QGroupBox("Расходы по категориям");
        auto *catLayout = new QVBoxLayout();
        for (const QString &cat : CATS) {
            auto *row = new QHBoxLayout();
            auto *lbl = new QLabel(cat + ": 0.00 ₽"); lbl->setMinimumWidth(160);
            auto *bar = new QProgressBar(); bar->setRange(0,100); bar->setMaximumHeight(16); bar->setFormat("%p%");
            catLabels[cat] = lbl;
            catBars[cat]   = bar;
            row->addWidget(lbl); row->addWidget(bar, 1);
            catLayout->addLayout(row);
        }
        catGroup->setLayout(catLayout);
        main->addWidget(catGroup);

        // --- Сигналы и слоты: связываем кнопки с методами ---
        connect(addBtn,      &QPushButton::clicked,          this, &MainWindow::addExpense);
        connect(descEdit,    &QLineEdit::returnPressed,       this, &MainWindow::addExpense);   // Enter в поле = добавить
        connect(delBtn,      &QPushButton::clicked,          this, &MainWindow::deleteSelected);
        connect(exportBtn,   &QPushButton::clicked,          this, &MainWindow::exportCSV);
        connect(filterCombo, &QComboBox::currentTextChanged, this, [this](const QString&){ refreshTable(); });
    }

    // Данные
    QVector<Expense> expenses; // все расходы — единственный источник данных
    double budget;             // бюджет на месяц

    // Виджеты формы
    QComboBox      *catCombo;  // выпадающий список категорий
    QLineEdit      *descEdit;  // поле описания
    QDoubleSpinBox *amountSpin;// поле суммы

    // Таблица и фильтр
    QTableWidget *table;
    QComboBox    *filterCombo;

    // Метки итогов
    QLabel *totalLabel, *budgetLabel, *remainLabel;

    // Задание B: словари виджетов — ключ = название категории
    QMap<QString, QProgressBar*> catBars;   // прогресс-бар каждой категории
    QMap<QString, QLabel*>       catLabels; // надпись с суммой каждой категории
};


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}

#include "main.moc"

