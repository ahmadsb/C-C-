#ifndef POLYMORPHISM_H__
#define POLYMORPHISM_H__

//// TextFormatter ////////////
typedef void (*Func)(void);
typedef char (*CharFunc)(void);

typedef struct TextFormatter{
    Func *Vptr; //virtual table of TextFormatter
}TextFormatter;

void init_ctor_Text_Formatter(TextFormatter* this);
void Dtor_TextFormatter(TextFormatter* this);  // virtual  
void print_Text_Formatter(TextFormatter* this, const char* text) ; // ..const = 0 ; virtual



// //// DefaultTextFormatter ////////////

int next_id;
// //get next ++
// typedef struct Ider Ider;

    
typedef struct DefaultTextFormatter{
    TextFormatter TF;
    int m_id;
    // Func* Vptr;
}DefaultTextFormatter;

void init_DefaultTextFormatter(DefaultTextFormatter*const this);
void Dtor_DefaultTextFormatter(DefaultTextFormatter*const this);
void copy_ctor_DefaultTextFormatter(DefaultTextFormatter*const this,DefaultTextFormatter*const other);
void print_DefaultTextFormatter(DefaultTextFormatter*const this, const char* text);//...const; virtual
void operator_equal_DefaultTextFormatter(DefaultTextFormatter*const this,DefaultTextFormatter*const other);

DefaultTextFormatter* generateFormatterArray();//??

typedef struct PrePostFixer{
    DefaultTextFormatter DTF;// &PPF == &DTF same positon
    char* m_pre;
    char* m_post;
}PrePostFixer;

void init_PrePostFixer(PrePostFixer*const  this, char* prefix, char* postfix);
void des_PrePostFixer(PrePostFixer*const this);
void copy_ctor_PrePostFixer(PrePostFixer*const this, PrePostFixer*const other);
void print_PrePostFixer(PrePostFixer*const this,const char* text) ;//virtual
void print_PrePostFixer_with_num(PrePostFixer*const this,long num, char symbol );//virtual symbol ='\0'
char getDefaultSymbol_PrePostFixer();//virtual

DefaultTextFormatter* generateFormatterArray();

//PrePostDollarFixer
typedef struct PrePostDollarFixer{
    PrePostFixer PPF;
}PrePostDollarFixer;

    void init_Ctor_PrePostDollarFixer(PrePostDollarFixer*const this, char* prefix, char* postfix );
    void copy_ctor_PrePostDollarFixer(PrePostDollarFixer*const this,PrePostDollarFixer*const other);
    void Des_PrePostDollarFixer(PrePostDollarFixer*const this);
    void print_with_int_PrePostDollarFixer( PrePostDollarFixer*const this,int num, char symbol ) ;// symbol with defualt value int num
    void print_with_long_PrePostDollarFixer(PrePostDollarFixer*const this, long num, char symbol) ;// symbol with defualt value long num
    void print_with_double_PrePostDollarFixer(PrePostDollarFixer*const this, double num, char symbol );// symbol with defualt value double num
    char getDefaultSymbol_PrePostDollarFixer();


typedef struct PrePostHashFixer{
    PrePostDollarFixer PPDF;
    int precision;
}PrePostHashFixer;

void init_Ctor_PrePostHashFixer(PrePostHashFixer* const this, int prc);//param:defualt value 4
void Dtor_PrePostHashFixer(PrePostHashFixer* const this);
void print_int_PrePostHashFixer(PrePostHashFixer* const this,int num, char symbol ) ;// defualt symbol '#'
void print_long_PrePostHashFixer(PrePostHashFixer* const this, long num, char symbol) ;// defualt symbol '#'
void print_double_PrePostHashFixer(PrePostHashFixer* const this, double num, char symbol);// defualt symbol '#'
char getDefaultSymbol_PrePostHashFixer();


// PrePostFloatDollarFixer 

typedef struct PrePostFloatDollarFixer{
    PrePostDollarFixer PPDF;
}PrePostFloatDollarFixer;

void init_Ctor_PrePostFloatDollarFixer(PrePostFloatDollarFixer* const this,char* prefix,char* postfix);
void Dtor_PrePostFloatDollarFixer(PrePostFloatDollarFixer* const this);
void print_PrePostFloatDollarFixer(PrePostFloatDollarFixer* const this,float num, char symbol);//'@'
char getDefaultSymbol_PrePostFloatDollarFixer();

//PrePostChecker
typedef struct PrePostChecker{
    PrePostFloatDollarFixer PPFDF;
}PrePostChecker;

void init_Ctor_PrePostChecker(PrePostChecker* const this);
void Dtor_PrePostChecker(PrePostChecker* const this);
void const printThisSymbolUsingFunc(PrePostChecker* const this);
void const printThisSymbolDirectly(PrePostChecker* const this);    
void const printDollarSymbolByCastUsingFunc(PrePostChecker* const this);
void const printDollarSymbolByScopeUsingFunc(PrePostChecker* const this);
void const printDollarSymbolByCastDirectly(PrePostChecker* const this);
void const printDollarSymbolByScopeDirectly(PrePostChecker* const this);

//Multiplier

typedef struct Multiplier{
    DefaultTextFormatter DTF;
    int m_times;
}Multiplier;

void init_Ctor_Multiplier(Multiplier* const this, int t );//defualt value 2
void Dtor_Multiplier(Multiplier* const this);
void const print_Multiplier(Multiplier* const this,const char*);
void copy_ctor_Multiplier(Multiplier* const this, Multiplier* const other);
int const getTimes() ;
void setTimes(Multiplier* const this, int t);


#endif