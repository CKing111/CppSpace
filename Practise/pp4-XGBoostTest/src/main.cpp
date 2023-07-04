#include <iostream>
#include <vector>
#include "TimeSeriesPredictor.h"

int main() {
    // 准备数据
    std::vector<float> data = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<float> labels = {2.0, 4.0, 6.0, 8.0, 10.0};
    std::vector<float> test_data = {6.0, 7.0, 8.0, 9.0, 10.0};

    // 构建时序预测类
    TimeSeriesPredictor predictor(10, 0.1, "objective=reg:squarederror", "eval_metric=rmse");
    predictor.SetData(data, labels);
    predictor.SetTestData(test_data);
    
    // 训练模型并进行预测
    predictor.Train();
    std::vector<float> results = predictor.Predict();
    
    // 打印预测结果
    for (float result : results) {
        std::cout << result << " ";
    }

    return 0;
}