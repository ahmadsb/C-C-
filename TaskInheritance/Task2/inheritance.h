#ifndef INHERITANCE_H__
#define INHERITANCE_H__
#include"box.h"
#include"shelf.h"
#include<stdio.h>
// static fun. in cpp --> it is fun. global in c.
typedef enum { PLASTIC, METAL, WOOD, PAPER, OTHER}Types;
const char* get_name_material(Types type);
typedef struct Materials{}Materials;
//defualt ctor of materials that is empty srtuct

typedef struct Material_t
{
    Types material;
}Material_t;
// defualt ctor material_t
void init_Material_t(Material_t* pM, Types mat);



#endif
