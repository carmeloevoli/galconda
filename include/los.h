#ifndef GALCONDA_LOS_H_
#define GALCONDA_LOS_H_

#include <cmath>

#include "constants.h"

struct domain {
  double magnetic_field_x;
  double magnetic_field_y;
  double magnetic_field_z;
  double magnetic_field_perp;
  double magnetic_field_total;
  double distance;
  double psik;
  double electron_density;
  double HI_density;
  double H2_density;
};

class LOS {
public:
    LOS() {
    }

    LOS(const double& ldeg_, const double& bdeg_) {
        l = deg2rad(ldeg_); // \phi in [0,2\pi]
        //los.b = (bdeg < 0) ? (90.0-bdeg)*DegToRad : -1; // \theta in [0,\pi]
        b = deg2rad(bdeg_);
        sin_l = std::sin(l);
        cos_l = std::cos(l);
        sin_b = std::sin(b);
        cos_b = std::cos(b);
        cos_b_cos_l = cos_b * cos_l;
        cos_b_sin_l = cos_b * sin_l;
    }

    virtual ~LOS() {
    }

    double l = 0;
    double b = 0;
    double sin_l = 0;
    double cos_l = 0;
    double sin_b = 0;
    double cos_b = 0;
    double cos_b_cos_l = 0;
    double cos_b_sin_l = 0;

    std::vector<domain> domains;
};

#endif