#ifndef TIME_SERIES_PREDICTOR_H_
#define TIME_SERIES_PREDICTOR_H_

#include <vector>
#include <xgboost/c_api.h>
/*
依赖
sudo pacman -S boost eigen openmpi python-numpy python-scipy python-scikit-learn python-pandas 
git clone --recursive git@github.com:dmlc/xgboost.git      # 没有dmlc-core文件夹,这个是xgboost的依赖。
                                                            需要clone xgboost时加上 --recursive参数,才能拉取dmlc-core:
cd xgboost
mkdir build
cd build 
cmake ..            // cmake -DUSE_CUDA=OFF ..
make -j4
*/
class TimeSeriesPredictor {
public:
    TimeSeriesPredictor(int num_round, float learning_rate, const char *objective, const char *eval_metric);
    void SetData(const std::vector<float> &data, const std::vector<float> &labels);
    void SetTestData(const std::vector<float> &test_data);
    void Train();
    std::vector<float> Predict();
    ~TimeSeriesPredictor();

private:
    int num_round_;
    float learning_rate_;
    const char *objective_;
    const char *eval_metric_;
    bst_ulong num_train_;
    bst_ulong num_test_;
    std::vector<float> data_;
    std::vector<float> labels_;
    std::vector<float> test_data_;
    DMatrixHandle dtrain_;
    DMatrixHandle dtest_;
    BoosterHandle bst_;
};

#endif  // TIME_SERIES_PREDICTOR_H_