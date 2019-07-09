#include"PhysicalBox.h"
#include"box.h"
// void ctor_PhysicalBox(PhysicalBox* phy_box, double l, double w, double h, Types t);
void defulat_ctor_PhysicalBox(PhysicalBox* this, double l, double w, double h, Types t){
   init_box(&(this->b) , l, w, h);
   init_Material_t(&(this->material_t),t);
   //print(this)
}
// void ctor_PhysicalBox_without_Measurement(PhysicalBox* phy_box, Types t);
void des_PhysicalBox(PhysicalBox* phy_box ){
    /*
    print physicalbox d,d,d with type
    des box;
    des of base*/
}