#pragma once

#include "Classifier.h"
#include "dataanalysis.h"
#include <unordered_map>

namespace randomforestc{


class RandomForestClassifier:public Classifier 
{
private:
  alglib::ae_int_t n_trees;
  // randomforestc::Item *bayesiantable;
  alglib::decisionforest df;
public:
  RandomForestClassifier ();
  RandomForestClassifier (const char* config_file);
  ~RandomForestClassifier ();
  void init_model (const char* config_file);
  void train_on_file (const char* training_file);
  void save_model (const char* model_file);
  void load_model (const char* model_file);
  void predicted_category (const double* features, int& res);
  void free_model ();
};

}

