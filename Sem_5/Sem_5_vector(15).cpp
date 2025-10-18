#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    // Данные
    vector<vector<double>> temp(5, vector<double>(30));
    vector<vector<double>> pressure(5, vector<double>(100));

    // Заполняем случайными значениями
    srand(time(0));
    for_each(temp.begin(), temp.end(), [](vector<double>& channel) {
        for_each(channel.begin(), channel.end(), [](double& value) {
            value = rand() % 40 + 20; // 20-60°C
            });
        });

    for_each(pressure.begin(), pressure.end(), [](vector<double>& channel) {
        for_each(channel.begin(), channel.end(), [](double& value) {
            value = rand() % 80 + 100; // 100-180 kPa
            });
        });


    // 1. Средняя температура по каналам
    cout << "\n1. Средние температуры:" << endl;
    vector<double> avg_temps(5);
    int channel_num = 1;
    for_each(temp.begin(), temp.end(), [&](const vector<double>& channel) {
        double sum = accumulate(channel.begin(), channel.end(), 0.0);
        avg_temps[channel_num - 1] = sum / channel.size();
        cout << "Канал " << channel_num++ << ": " << avg_temps[channel_num - 2] << "°C" << endl;
        });

    // 2. Минимальное и максимальное давление
    cout << "\n2. Минимальное и максимальное давление:" << endl;
    channel_num = 1;
    for_each(pressure.begin(), pressure.end(), [&](const vector<double>& channel) {
        auto min_it = min_element(channel.begin(), channel.end());
        auto max_it = max_element(channel.begin(), channel.end());
        cout << "Канал " << channel_num++ << ": min=" << *min_it << ", max=" << *max_it << endl;
        });

    // 3. Разности между соседними измерениями температуры
    cout << "\n3. Разности температур (первые 5):" << endl;
    channel_num = 1;
    for_each(temp.begin(), temp.end(), [&](const vector<double>& channel) {
        cout << "Канал " << channel_num++ << ": ";
        for (int j = 1; j < 6; j++) {
            double diff = channel[j] - channel[j - 1];
            cout << diff << " ";
        }
        cout << endl;
        });

    // 4. Канал с наибольшей вариацией температуры
    cout << "\n4. Канал с наибольшей вариацией температуры:" << endl;
    double max_variation = 0;
    int max_var_channel = 0;
    channel_num = 1;
    for_each(temp.begin(), temp.end(), [&](const vector<double>& channel) {
        auto min_it = min_element(channel.begin(), channel.end());
        auto max_it = max_element(channel.begin(), channel.end());
        double variation = *max_it - *min_it;
        if (variation > max_variation) {
            max_variation = variation;
            max_var_channel = channel_num;
        }
        channel_num++;
        });
    cout << "Канал " << max_var_channel << " (вариация: " << max_variation << "°C)" << endl;

    // 5. Нормализация давления
    cout << "\n5. Нормализованное давление (первые 5 значений):" << endl;
    vector<vector<double>> norm_pressure(5);
    channel_num = 1;
    for_each(pressure.begin(), pressure.end(), [&](const vector<double>& channel) {
        double min_val = *min_element(channel.begin(), channel.end());
        double max_val = *max_element(channel.begin(), channel.end());
        double range = max_val - min_val;

        norm_pressure[channel_num - 1].resize(channel.size());
        transform(channel.begin(), channel.end(), norm_pressure[channel_num - 1].begin(),
            [min_val, range](double value) {
                return (value - min_val) / range;
            });

        cout << "Канал " << channel_num++ << ": ";
        for (int j = 0; j < 5; j++) {
            cout << norm_pressure[channel_num - 2][j] << " ";
        }
        cout << endl;
        });

    // 6. Пики давления (>0.9)
    cout << "\n6. Пики давления (>0.9):" << endl;
    channel_num = 1;
    for_each(norm_pressure.begin(), norm_pressure.end(), [&](const vector<double>& channel) {
        cout << "Канал " << channel_num++ << ": ";
        int count = 0;
        for_each(channel.begin(), channel.end(), [&](double value) {
            if (value > 0.9) {
                cout << value << " ";
                count++;
            }
            });
        if (count == 0) cout << "нет пиков";
        cout << endl;
        });

    // 7. Канал с максимальной средней температурой
    cout << "\n7. Канал с максимальной средней температурой:" << endl;
    auto max_temp_it = max_element(avg_temps.begin(), avg_temps.end());
    int max_channel = distance(avg_temps.begin(), max_temp_it) + 1;
    cout << "Канал " << max_channel << " (" << *max_temp_it << "°C)" << endl;

    return 0;
}
