#ifndef __POINTSET_H__
#define __POINTSET_H__
#include <vector>
#include <memory>
#include "geometry.h"

struct GenericAttributeContainer;

struct PointSet {
    PointSet() : data(new std::vector<vec3>()), attr() {}
    PointSet(std::shared_ptr<std::vector<vec3> > ext) : data(ext), attr() {}

    int size() const { return data->size(); }
          vec3& operator[](const int i)       { return data->at(i); }
    const vec3& operator[](const int i) const { return data->at(i); }

    void bbox(vec3 &min, vec3 &max);
    void resize(const int n);
    void push_back(const vec3 &p);
    void delete_points(const std::vector<bool> &to_kill, std::vector<int> &old2new);

    using       iterator = std::vector<vec3>::iterator;
    using const_iterator = std::vector<vec3>::const_iterator;

          iterator begin()       { return data->begin(); }
    const_iterator begin() const { return data->begin(); }
          iterator end()       { return data->end(); }
    const_iterator end() const { return data->end(); }

    void resize_attrs();
    void compress_attrs(const std::vector<int> &old2new);

    std::shared_ptr<std::vector<vec3> > data;
    std::vector<std::weak_ptr<GenericAttributeContainer> > attr;
};

#endif //__POINTSET_H__
