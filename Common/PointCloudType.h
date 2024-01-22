#pragma once

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

using Point_t = pcl::PointXYZRGBNormal;
using Normal_t = pcl::PointNormal;

using PC_t = pcl::PointCloud<Point_t>;
using NormalPC_t = pcl::PointCloud<Normal_t>;