#include "user_matrix_transform.h"
#include "user_all_h_data.h"

/*
 *@biref: abc -> alpha beta
*/
void Clarke_Marco(type_default *v)
{
    v->Alpha = (v->As * 0.6667 - (v->Bs + v->Cs) * 0.3333);
    v->Beta  = (v->Bs - v->Cs) * 0.57735;
}

/*
 *@brief: alpha beta -> abc
*/
void IClarke_Marco(type_default *v)
{
    v->As  = v->Alpha;		
    v->Bs  = 0.866 * v->Beta - 0.5 * v->Alpha;  
    v->Cs  = -0.5 * v->Alpha - 0.866 * v->Beta;
}

/*
 *@brief: alpha beta -> D Q
*/
void Park_Marco(type_default *v)
{
    v->Ds = (v->Alpha * v->Cosine + v->Beta * v->Sine);
    v->Qs = (v->Beta * v->Cosine - v->Alpha * v->Sine);
}

/*
 *@brief: D Q -> alpha beta
*/
void IPark_Marco(type_default *v)
{
    v->Alpha = (v->Ds * v->Cosine - v->Qs * v->Sine);
    v->Beta  = (v->Qs * v->Cosine + v->Ds * v->Sine);

    // v->As = v->Alpha;
    // v->Bs = 0.866 * v->Beta - 0.5 * v->Alpha;
    // v->Cs = -0.5 * v->Alpha - 0.866 * v->Beta;
}




