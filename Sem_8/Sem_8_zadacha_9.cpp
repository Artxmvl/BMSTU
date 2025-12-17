#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Простая структура для хранения данных нейронного слоя
struct NeuralLayer {
    int neuron_count;
    int input_count;
    double** weights;
    double* inputs;
    double* outputs;
};

// Создаем слой нейронов
NeuralLayer createLayer(int neurons, int inputs) {
    NeuralLayer layer;
    layer.neuron_count = neurons;
    layer.input_count = inputs;
    layer.outputs = nullptr;  // Инициализируем как nullptr

    // Создаем матрицу весов
    layer.weights = new double* [neurons];
    srand(time(0));

    for (int i = 0; i < neurons; i++) {
        layer.weights[i] = new double[inputs];
        for (int j = 0; j < inputs; j++) {
            // Случайные веса от -1.0 до 1.0
            layer.weights[i][j] = (rand() % 2001) / 1000.0 - 1.0;
        }
    }

    // Создаем входные сигналы
    layer.inputs = new double[inputs];
    for (int i = 0; i < inputs; i++) {
        layer.inputs[i] = (i + 1) * 0.1;
    }

    return layer;
}

// Вычисляем выходы нейронов
void calculateOutputs(NeuralLayer& layer) {
    // Если выходы уже существуют, удаляем их
    if (layer.outputs != nullptr) {
        delete[] layer.outputs;
    }

    layer.outputs = new double[layer.neuron_count];

    for (int i = 0; i < layer.neuron_count; i++) {
        double sum = 0.0;
        for (int j = 0; j < layer.input_count; j++) {
            sum += layer.weights[i][j] * layer.inputs[j];
        }
        layer.outputs[i] = sum;
    }
}

// Нормализуем веса
void normalizeWeights(NeuralLayer& layer) {
    for (int i = 0; i < layer.neuron_count; i++) {
        double total = 0.0;
        for (int j = 0; j < layer.input_count; j++) {
            total += abs(layer.weights[i][j]);
        }

        if (total > 1.0) {
            for (int j = 0; j < layer.input_count; j++) {
                layer.weights[i][j] /= total;
            }
        }
    }
}

// Показываем информацию о слое
void showLayerInfo(const NeuralLayer& layer, const string& title) {
    cout << "\n=== " << title << " ===" << endl;

    cout << "Веса:" << endl;
    cout << fixed << setprecision(3);
    for (int i = 0; i < layer.neuron_count; i++) {
        cout << "Нейрон " << i + 1 << ": ";
        for (int j = 0; j < layer.input_count; j++) {
            cout << setw(6) << layer.weights[i][j] << " ";
        }
        cout << endl;
    }

    if (layer.outputs != nullptr) {
        cout << "\nВыходы:" << endl;
        for (int i = 0; i < layer.neuron_count; i++) {
            cout << "Нейрон " << i + 1 << ": " << layer.outputs[i] << endl;
        }
    }
}

// Освобождаем память
void deleteLayer(NeuralLayer& layer) {
    // Удаляем веса
    for (int i = 0; i < layer.neuron_count; i++) {
        delete[] layer.weights[i];
    }
    delete[] layer.weights;

    // Удаляем входы
    delete[] layer.inputs;

    // Удаляем выходы (если они есть)
    if (layer.outputs != nullptr) {
        delete[] layer.outputs;
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    int neurons, inputs;
    cout << "Количество нейронов: ";
    cin >> neurons;
    cout << "Количество входов: ";
    cin >> inputs;

    // Создаем и тестируем слой
    NeuralLayer layer = createLayer(neurons, inputs);

    cout << "ШАГ 1: Исходные веса и первый расчет" << endl;
    showLayerInfo(layer, "ИСХОДНЫЕ ВЕСА");
    calculateOutputs(layer);
    showLayerInfo(layer, "РЕЗУЛЬТАТЫ БЕЗ НОРМАЛИЗАЦИИ");

    cout << "ШАГ 2: Нормализация и перерасчет" << endl;
    normalizeWeights(layer);
    calculateOutputs(layer);  // Просто пересчитываем - функция сама удалит старые выходы
    showLayerInfo(layer, "РЕЗУЛЬТАТЫ С НОРМАЛИЗАЦИЕЙ");

    // Очищаем память
    deleteLayer(layer);

    
    return 0;
}