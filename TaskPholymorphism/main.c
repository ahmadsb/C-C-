#include "pholymorphism.h"
#include<stdio.h>
#include<stdlib.h>

void doPrePostFixer();
void doPrePostDollarFixer();
void doPrePostChecker();
void doPrePostFloatDollarFixer();
void runAsPrePostFixerRef( PrePostFixer*const pp);
void runAsPrePostDollarFixerRef(PrePostDollarFixer*const pp);
void runAsPrePostDollarFixerObj(PrePostDollarFixer*const pp);
void runAsPrePostHashFixerRef(PrePostHashFixer*const pp);
void doFormatterArray();
void doFormatterPtrs();
void doFormatterDynamicArray();
void doMultiplier();
int main()
{
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

    PrePostHashFixer hfix;
    runAsPrePostFixerRef(&(hfix.PPDF.PPF));
    runAsPrePostDollarFixerRef(&(hfix.PPDF));
    runAsPrePostDollarFixerObj(&(hfix.PPDF));
    runAsPrePostHashFixerRef(&(hfix));

    doMultiplier();

    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();

    printf("\n--- End main() ---\n\n");

    return 0;
}


void doPrePostFixer()
{
    printf("\n--- start doPrePostFixer() ---\n\n");

    PrePostFixer angleBrackets;
    init_PrePostFixer(&(angleBrackets),"<<< ", " >>>");
    print_PrePostFixer(&(angleBrackets),"Hello World!");
    print_PrePostFixer_with_num(&(angleBrackets),-777,'\0');
    print_PrePostFixer_with_num(&(angleBrackets),350,'#');
    print_PrePostFixer_with_num(&(angleBrackets),3.14,'\0');
    printf("\n--- end doPrePostFixer() ---\n\n");
}

void doPrePostDollarFixer()
{
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixer asterisks;
    init_Ctor_PrePostDollarFixer(&(asterisks),"***** ", " *****");
    print_with_int_PrePostDollarFixer(&(asterisks),-777,getDefaultSymbol_PrePostDollarFixer()) ;// symbol with defualt value int num
    print_with_int_PrePostDollarFixer(&(asterisks),350,'#') ;
    print_with_int_PrePostDollarFixer(&(asterisks),3.14f,getDefaultSymbol_PrePostDollarFixer()) ;

    printf("\n--- end doPrePostDollarFixer() ---\n\n");
}

void doPrePostChecker()
{
    printf("\n--- start doPrePostChecker() ---\n\n");
        PrePostChecker check;
        init_Ctor_PrePostChecker(&(check));
        printThisSymbolUsingFunc(&(check));
        printThisSymbolDirectly(&(check)); 
        printDollarSymbolByCastDirectly(&(check));
        printDollarSymbolByScopeDirectly(&(check));
        printDollarSymbolByCastUsingFunc(&(check));
        printDollarSymbolByScopeUsingFunc(&(check));


    printf("\n--- end doPrePostChecker() ---\n\n");
}

void doPrePostFloatDollarFixer()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
    PrePostFloatDollarFixer hashes;
    init_Ctor_PrePostFloatDollarFixer(&(hashes),"### ", " ###");
    print_PrePostFloatDollarFixer(&(hashes),-777,'@');
    print_PrePostFloatDollarFixer(&(hashes),350,'#');
    print_PrePostFloatDollarFixer(&(hashes),3.14f,'@');

 
    PrePostDollarFixer hashes2;
    copy_ctor_PrePostDollarFixer( &(hashes2), &(hashes.PPDF) );
    print_with_double_PrePostDollarFixer(&(hashes2),7.5,'@');
    print_with_int_PrePostDollarFixer(&(hashes2),100,'@');

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
}

void runAsPrePostFixerRef(PrePostFixer*const pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    print_PrePostFixer_with_num(pp,123,'$');
    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(PrePostDollarFixer*const pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");
    print_with_int_PrePostDollarFixer(pp,123,'$');

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(PrePostDollarFixer*const pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    print_with_int_PrePostDollarFixer(pp,123,'$');

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(PrePostHashFixer*const pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    print_int_PrePostHashFixer(pp,123,'#');

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    printf("\n--- start doMultiplier() ---\n\n");

    Multiplier m1;
    init_Ctor_Multiplier(&m1, 3);
     Multiplier m2;
    init_Ctor_Multiplier(&m2, 5);

    Multiplier m3;
    copy_ctor_Multiplier(&m3, &m1);
    Multiplier m4;
    copy_ctor_Multiplier(&m4, &m2);

    print_Multiplier(&m1, "abc ");
    print_Multiplier(&m2, "abc ");
    print_Multiplier(&m3, "abc ");
    print_Multiplier(&m4, "abc ");

    printf("\n--- start doMultiplier() ---\n\n");
}

void doFormatterArray()
{
    printf("\n--- start doFormatterArray() ---\n\n");

    // DefaultTextFormatter formatters[3];
    // PrePostDollarFixer* s =(PrePostDollarFixer*) malloc(sizeof(PrePostDollarFixer));
    // Multiplier* b =(Multiplier*) malloc(sizeof(Multiplier));
    // PrePostChecker* c =(PrePostChecker*) malloc(sizeof(PrePostChecker));
    // init_Ctor_PrePostDollarFixer(  s  ,"!!! ", " !!!"); 
    // init_Ctor_Multiplier(b, 4);
    // init_Ctor_PrePostChecker( c);
    // formatters[0] = s->PPF.DTF;
    // formatters[1] = b->DTF;
    // formatters[2] = c->PPFDF.PPDF.PPF.DTF;

    // for (int i = 0; i < 3; ++i)
    //     formatters[i].TF.Vptr[1]();

    printf("\n--- end doFormatterArray() ---\n\n");
}

void doFormatterPtrs()
{
    printf("\n--- start doFormatterPtrs() ---\n\n");

//     DefaultTextFormatter* pfmt[] =
//     {
//         new PrePostDollarFixer("!!! ", " !!!"),
//         new Multiplier(4),
//         new PrePostChecker()
//     };

//     for (int i = 0; i < 3; ++i)
//         pfmt[i]->print("Hello World!");

//     for (int i = 2; i >= 0; --i)
//         delete pfmt[i];

    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    DefaultTextFormatter* formatters = generateFormatterArray();
    
    for (int i = 0; i < 3; ++i)
         formatters[i].TF.Vptr[1]();

    free(formatters);

    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}





