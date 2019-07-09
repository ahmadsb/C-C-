#include"inheritance.h"
const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };

// shuold be inline
// const char* get_name_material( Types type){
//     // [ =" " ] equal string put on  data segment so don't put zevel value outside scope
//     // array names = zevel outside scope but ptr to string not zevel
//     // but int/.. not on data segment so put zevel value outside scope
//     const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
//     // inside names variables globaly
//     return names[type];
// }


void init_Material_t(Material_t* pM, Types mat){
        pM->material = mat;
        printf("Material created, set to %s\n",names[pM->material]); 
}


