
#ifndef PHYSICAL_BOX_H
#define PHYSICAL_BOX_H
#include"box.h"
#include"inheritance.h"
typedef struct PhysicalBox{
    Box b;
    Material_t material_t;

}PhysicalBox;

// void defulat_ctor_PhysicalBox(PhysicalBox* phy_box, double l, double w, double h);
// void ctor_PhysicalBox(PhysicalBox* phy_box, double l, double w, double h, Types t);
// void ctor_PhysicalBox_without_Measurement(PhysicalBox* phy_box, Types t);
// void des_PhysicalBox(PhysicalBox* phy_box );
#endif