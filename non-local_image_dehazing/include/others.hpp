#ifndef __OTHERS_HPP__
#define __OTHERS_HPP__

#include <opencv2/core.hpp>
#include <vector>
#include "kd_tree.hpp"

/** @brief Calculate Dark Channel*/
void calcDarkChannel(const cv::Mat_<cv::Vec3b>& src, cv::Mat_<uchar>& dst, const int s = 15);

void estimateAtmosphericLight(const cv::Mat_<cv::Vec3b>& src, 
    const cv::Mat_<uchar>& dark_channel, cv::Vec3d& A);

/** @brief convert cartesian coordinates to spherical coordinates and keep longitude and latitude*/
void spherical_coordinates(const std::vector<cv::Point3d>& vertex_table, std::vector<cv::Point2d>& sph_table);

/** @brief overload spherical_coordinates*/
void spherical_coordinates(const cv::Mat& img, std::vector<cv::Point2d>& img_sph, std::vector<double>& r,
    cv::Vec3d& A);

/** @brief clustering the haze image*/
void cluster_img(kd_node* root, const std::vector<cv::Point2d>& sph_table,
    const std::vector<cv::Point2d>& img_sph, std::vector<std::vector<int>>& cluster_result);

/** @brief calculate the low bound of transmission and standard deviation*/
void lowBound_delta(const std::vector<std::vector<int>>& cluster_result, const std::vector<double>& r,
    const cv::Mat& img, std::vector<double>& t_LB, std::vector<double>& delta);

#endif