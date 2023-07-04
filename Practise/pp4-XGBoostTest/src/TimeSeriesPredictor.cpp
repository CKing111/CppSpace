#include "TimeSeriesPredictor.h"

#include <iostream>

TimeSeriesPredictor::TimeSeriesPredictor(int num_round, float learning_rate, const char *objective, const char *eval_metric)
    : num_round_(num_round), learning_rate_(learning_rate), objective_(objective), eval_metric_(eval_metric) {}

void TimeSeriesPredictor::SetData(const std::vector<float> &data, const std::vector<float> &labels) {
    data_ = data;
    labels_ = labels;
    num_train_ = data.size();
}

void TimeSeriesPredictor::SetTestData(const std::vector<float> &test_data) {
    test_data_ = test_data;
    num_test_ = test_data.size();
}

void TimeSeriesPredictor::Train() {
    // 创建DMatrix
    XGDMatrixCreateFromMat(data_.data(), num_train_, 1, NAN, &dtrain_);
    XGDMatrixCreateFromMat(test_data_.data(), num_test_, 1, NAN, &dtest_);
    XGDMatrixSetFloatInfo(dtrain_, "label", labels_.data(), num_train_);

    // 创建模型
    const char *params[] = {objective_, eval_metric_, nullptr};
    XGBoosterCreate(&dtrain_, 1, &bst_);
    
    // 训练模型
    for (int i = 0; i < num_round_; ++i) {
        XGBoosterUpdateOneIter(bst_, i, dtrain_);
    }
}

std::vector<float> TimeSeriesPredictor::Predict() {
    bst_ulong out_len;
    const float *out_result;
    XGBoosterPredict(bst_, dtest_, 0, 0, &out_len, &out_result);
    return std::vector<float>(out_result, out_result + out_len);
}

TimeSeriesPredictor::~TimeSeriesPredictor() {
    XGDMatrixFree(dtrain_);
    XGDMatrixFree(dtest_);
    XGBoosterFree(bst_);
}