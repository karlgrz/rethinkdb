#ifndef CLUSTERING_ADMINISTRATION_MAIN_JSON_IMPORT_HPP_
#define CLUSTERING_ADMINISTRATION_MAIN_JSON_IMPORT_HPP_

#include <string>

#include "errors.hpp"

class scoped_cJSON_t;

class json_importer_t {
public:
    // Returns false upon EOF.
    virtual bool get_json(scoped_cJSON_t *out) = 0;
    virtual ~json_importer_t() { }
};

class csv_to_json_importer_t : public json_importer_t {
public:
    csv_to_json_importer_t(std::string separators, std::string filepath);

    // Returns false upon EOF.
    bool get_json(scoped_cJSON_t *out);

private:
    void import_json_from_file(std::string separators, std::string filepath);

    std::vector<std::string> column_names_;
    std::vector<std::vector<std::string> > rows_;

    int position_;

    DISABLE_COPYING(csv_to_json_importer_t);
};


#endif  // CLUSTERING_ADMINISTRATION_MAIN_JSON_IMPORT_HPP_
