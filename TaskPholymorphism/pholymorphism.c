#include"pholymorphism.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Text Formatter
//virtual table



Func g_arr_VTTextFormatter[] ={
    (Func)Dtor_TextFormatter,
    (Func)print_Text_Formatter
    };

void init_ctor_Text_Formatter(TextFormatter* this){
    this->Vptr = g_arr_VTTextFormatter;
}
void Dtor_TextFormatter(TextFormatter* this){  
    printf("Destructor Text Formatter\n");
}  
void print_Text_Formatter(TextFormatter* this, const char* text) { // ..const = 0 ; virtual
    printf("the text %s",text);
}

// //DefaultTextFormatter

Func g_arr_VTDefaultTextFormatter[] ={
    (Func)Dtor_DefaultTextFormatter,
    (Func)print_DefaultTextFormatter
    };
int next_id = 0;
void init_DefaultTextFormatter(DefaultTextFormatter*const this){
    init_ctor_Text_Formatter(&(this->TF));// ctor defualt of struct base
    this->TF.Vptr = g_arr_VTDefaultTextFormatter;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", next_id);
    this->m_id = next_id++;//m_member
}
void Dtor_DefaultTextFormatter(DefaultTextFormatter*const this){
    /*Dtor of base*/
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->m_id);
    this->TF.Vptr = g_arr_VTTextFormatter; // set virtual table to struct base
    Dtor_TextFormatter(&(this->TF)); // call Dtor of struct base

}
void copy_ctor_DefaultTextFormatter(DefaultTextFormatter*const this,DefaultTextFormatter*const other){
    init_ctor_Text_Formatter(&(this->TF));
    this->m_id = other->m_id;
    // this->Vptr = other->Vptr; // set virtual table of copy cnot
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->m_id, this->m_id);
}

void print_DefaultTextFormatter(DefaultTextFormatter*const this, const char* text) {
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");  // function inline printFunc  
    printf("%s\n", text);
}


void operator_equal_DefaultTextFormatter(DefaultTextFormatter*const this, DefaultTextFormatter*const other){
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->m_id, this->m_id);

}
DefaultTextFormatter* generateFormatterArray()
{
    DefaultTextFormatter* temp;
    temp=(DefaultTextFormatter*)malloc(sizeof(DefaultTextFormatter) * 3);
    for(int i= 0; i< 3; i++){
        init_DefaultTextFormatter(&(temp[i]));
    }
    return temp;
} 


//PrePostFixer
Func g_arr_VTPrePostFixer[] ={
    (Func)des_PrePostFixer, 
    (Func)print_PrePostFixer,
    (Func)print_PrePostFixer_with_num,
    (Func)getDefaultSymbol_PrePostFixer };

void init_PrePostFixer(PrePostFixer*const  this, char* prefix, char* postfix){
    init_DefaultTextFormatter(&(this->DTF));
    this->DTF.TF.Vptr = g_arr_VTPrePostFixer;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", prefix, postfix);
    this->m_post = postfix;
    this->m_pre = prefix;
}
void copy_ctor_PrePostFixer(PrePostFixer*const this, PrePostFixer*const other){
    init_DefaultTextFormatter(&(this->DTF));

}
void des_PrePostFixer(PrePostFixer*const this){
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n",this->m_pre,this->m_post);
    this->DTF.TF.Vptr = g_arr_VTDefaultTextFormatter;// set to VT of base
    Dtor_DefaultTextFormatter(&(this->DTF));// dtor of base
    
}
void print_PrePostFixer(PrePostFixer*const this,const char* text) {//virtual
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");  // function inline printFunc  
    printf("%s%s%s\n", this->m_pre, text, this->m_post);
    }
void print_PrePostFixer_with_num(PrePostFixer*const this,long num, char symbol )//virtual symbol ='\0'
{
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");  // function inline printFunc  
    printf("-->\n");
    
    if (symbol)    
        {
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this->m_pre, symbol, num, this->m_post);
        }
    else{
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->m_pre, num, this->m_post);

    }
}
//vitrual
char getDefaultSymbol_PrePostFixer(){return '\0';}



//PrePostDollarFixer
Func g_arr_VTPrePostDollarFixer[] ={
    (Func)Des_PrePostDollarFixer,
    (Func)print_PrePostFixer,//question??
    (Func)print_with_long_PrePostDollarFixer,
    (Func)getDefaultSymbol_PrePostDollarFixer
};
 char DEFAULT_SYMBOL = '$';// static

void init_Ctor_PrePostDollarFixer(PrePostDollarFixer*const this, char* prefix, char* postfix ){
    init_PrePostFixer(&(this->PPF), prefix, postfix);
    this->PPF.DTF.TF.Vptr = g_arr_VTPrePostDollarFixer;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", prefix, postfix);

}
void copy_ctor_PrePostDollarFixer(PrePostDollarFixer*const this,PrePostDollarFixer*const other){
    init_PrePostFixer(&(this->PPF), this->PPF.m_pre, this->PPF.m_post);
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->PPF.m_pre, this->PPF.m_post);
    
}
void Des_PrePostDollarFixer(PrePostDollarFixer*const this){
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->PPF.m_pre, this->PPF.m_post);
    this->PPF.DTF.TF.Vptr =g_arr_VTPrePostFixer;
    des_PrePostFixer(&(this->PPF));
}

void print_with_int_PrePostDollarFixer(PrePostDollarFixer*const this,int num, char symbol ) {   // symbol with defualt value int num
    printf("[PrePostDollarFixer::print(int, char)]");  // function inline printFunc  
    printf("-->\n");
    print_with_long_PrePostDollarFixer(this, num, symbol);

    }
 
void print_with_long_PrePostDollarFixer(PrePostDollarFixer*const this,long num, char symbol) {// symbol with defualt value long num
    printf("[PrePostDollarFixer::print(long, char)]");  // function inline printFunc  
    printf("-->\n");
    print_PrePostFixer_with_num(&(this->PPF),num, symbol);

    }
void print_with_double_PrePostDollarFixer(PrePostDollarFixer*const this,double num, char symbol ){// symbol with defualt value double num
    printf("[PrePostDollarFixer::print(double, char)]");  // function inline printFunc  
    printf("%s%c%F%s\n", this->PPF.m_pre, symbol, num, this->PPF.m_post);
    }
char getDefaultSymbol_PrePostDollarFixer(){return DEFAULT_SYMBOL;}//'$'

//PrePostHashFixer 
Func g_arr_VTPrePostHashFixer[] ={
    (Func)Des_PrePostDollarFixer,
    (Func)print_PrePostFixer,//question??
    (Func)print_with_long_PrePostDollarFixer,
    (Func)getDefaultSymbol_PrePostDollarFixer
};
char DEFAULT_SYMBOL_PrePostHashFixer = '#';// static
void init_Ctor_PrePostHashFixer(PrePostHashFixer* const this, int prc){//param:defualt value 4
    init_Ctor_PrePostDollarFixer(&(this->PPDF),"===> ", " <===");
    this->PPDF.PPF.DTF.TF.Vptr = g_arr_VTPrePostHashFixer;
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", "===> ", " <===", prc);   
    // print(9999.9999);

}
void Dtor_PrePostHashFixer(PrePostHashFixer* const this){
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", this->PPDF.PPF.m_pre, this->PPDF.PPF.m_post);
    Des_PrePostDollarFixer(&(this->PPDF));
}
// defualt symbol '#'
void print_int_PrePostHashFixer(PrePostHashFixer* const this, int num, char symbol ) {
    printf("[PrePostHashFixer::print(int, char)]");  // function inline printFunc  
    printf("-->\n");
    print_double_PrePostHashFixer(this, num, symbol);
}
void print_long_PrePostHashFixer(PrePostHashFixer* const this, long num, char symbol){
    printf("[PrePostHashFixer::print(long, char)]");  // function inline printFunc  
    printf("-->\n");
    print_double_PrePostHashFixer(this, num, symbol);
}
void print_double_PrePostHashFixer(PrePostHashFixer* const this, double num, char symbol){
    // printf("[PrePostHashFixer::print(double, char)]");  // function inline printFunc  
    // printf("-->\n");
}
char getDefaultSymbol_PrePostHashFixer(){return DEFAULT_SYMBOL_PrePostHashFixer;}

//PrePostFloatDollarFixer
Func g_arr_PrePostFloatDollarFixer[] ={
    (Func)Dtor_PrePostFloatDollarFixer,
    (Func)print_PrePostFixer,//question??
    (Func)print_with_long_PrePostDollarFixer,
    (Func)getDefaultSymbol_PrePostFloatDollarFixer
};

char DEFAULT_SYMBOL_PrePostFloatDollarFixer = '@';// static

void init_Ctor_PrePostFloatDollarFixer(PrePostFloatDollarFixer* const this,char* prefix,char* postfix){
    init_Ctor_PrePostDollarFixer(&(this->PPDF),prefix,postfix);
    this->PPDF.PPF.DTF.TF.Vptr =g_arr_PrePostFloatDollarFixer;
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n",prefix,postfix);
}
void Dtor_PrePostFloatDollarFixer(PrePostFloatDollarFixer* const this){
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", this->PPDF.PPF.m_pre, this->PPDF.PPF.m_post);
    Des_PrePostDollarFixer(&(this->PPDF));
}
void print_PrePostFloatDollarFixer(PrePostFloatDollarFixer* const this,float num, char symbol){//'@'
    if(sizeof(symbol)!=1){ // check if char variable not
        printf("[PrePostFloatDollarFixer::print(float)]");  // function inline printFunc  
        printf("-->\n");
        printf("[PrePostFloatDollarFixer::print(float, char)]");  // function inline printFunc  
        printf("%s%c%.2F%s\n", this->PPDF.PPF.m_post, symbol, num, this->PPDF.PPF.m_post);
    }
   else{
        printf("[PrePostFloatDollarFixer::print(float, char)]");
        printf("%s%c%.2F%s\n", this->PPDF.PPF.m_pre, symbol, num, this->PPDF.PPF.m_post);

   }
    
    }
char getDefaultSymbol_PrePostFloatDollarFixer(){return DEFAULT_SYMBOL_PrePostFloatDollarFixer;}

//PrePostChecker
Func g_arr_VTPrePostChecker[] ={
    (Func)Dtor_PrePostChecker,
    (Func)print_PrePostFixer,//question??
    (Func)print_with_long_PrePostDollarFixer,
    (Func)getDefaultSymbol_PrePostDollarFixer
};
void init_Ctor_PrePostChecker(PrePostChecker* const this){
    init_Ctor_PrePostFloatDollarFixer(&(this->PPFDF),"[[[[ ", " ]]]]");
    this->PPFDF.PPDF.PPF.DTF.TF.Vptr = g_arr_VTPrePostChecker;
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", "[[[[ ", " ]]]]");
}

void Dtor_PrePostChecker(PrePostChecker* const this){
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->PPFDF.PPDF.PPF.m_pre, this->PPFDF.PPDF.PPF.m_post);
    this->PPFDF.PPDF.PPF.DTF.TF.Vptr = g_arr_VTPrePostDollarFixer;
    Dtor_PrePostFloatDollarFixer(&(this->PPFDF));
}

void const printThisSymbolUsingFunc(PrePostChecker* const this)
{
    printf("[PrePostChecker::printThisSymbolUsingFunc()]");  // function inline printFunc  
    printf("Default symbol is %c\n",(((CharFunc)(this->PPFDF.PPDF.PPF.DTF.TF.Vptr[3]))() ));//call funciton
}
void const printThisSymbolDirectly(PrePostChecker* const this){
    printf("[PrePostChecker::printThisSymbolDirectly()]");  // function inline printFunc  
    printf("Default symbol is %c\n", (((CharFunc)(this->PPFDF.PPDF.PPF.DTF.TF.Vptr[3]))() ));
}   
void const printDollarSymbolByCastUsingFunc(PrePostChecker* const this){
    printf("[PrePostChecker::printDollarSymbolByCastUsingFunc()]");
    printf("Default symbol is %c\n", (((CharFunc)(this->PPFDF.PPDF.PPF.DTF.TF.Vptr[3]))() ));
}
void const printDollarSymbolByScopeUsingFunc(PrePostChecker* const this){
    printf("[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");
    printf("Default symbol is %c\n", (((CharFunc)(this->PPFDF.PPDF.PPF.DTF.TF.Vptr[3]))() ));
}
void const printDollarSymbolByCastDirectly(PrePostChecker* const this){
    printf("[PrePostChecker::printDollarSymbolByCastDirectly()]");
    printf("Default symbol is %c\n",(((CharFunc)(this->PPFDF.PPDF.PPF.DTF.TF.Vptr[3]))() ));
}
void const printDollarSymbolByScopeDirectly(PrePostChecker* const this){
    printf("[PrePostChecker::printDollarSymbolByScopeDirectly()]");
    printf("Default symbol is %c\n",(((CharFunc)(this->PPFDF.PPDF.PPF.DTF.TF.Vptr[3]))() ));
}


//Multiplier
Func g_arr_VTMultiplier[] ={
    (Func)Dtor_Multiplier,
    (Func)print_Multiplier
};
void init_Ctor_Multiplier(Multiplier* const this, int t ){// defualt value 2
    init_DefaultTextFormatter(&(this->DTF));
    this->DTF.TF.Vptr = g_arr_VTMultiplier;
    this->m_times = t;
}
void Dtor_Multiplier(Multiplier* const this){
    this->DTF.TF.Vptr = g_arr_VTDefaultTextFormatter;
    Dtor_DefaultTextFormatter(&(this->DTF));
}
void copy_ctor_Multiplier(Multiplier* const this, Multiplier* const other){
init_DefaultTextFormatter(&(this->DTF));
this->m_times = other->m_times;
}
void const print_Multiplier(Multiplier* const this,const char*text)
{
    printf("[Multiplier::print(const char*)]");
    for (int i = 0; i < this->m_times ; i++)
        printf("%s", text);
    printf("\n");
}
int const getTimes(Multiplier* const this){
    return this->m_times;
}
void setTimes(Multiplier* const this, int t){
    this->m_times=t;
}





