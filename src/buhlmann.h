#ifndef _BUHLMANN_H_
#define _BUHLMANN_H_

struct compartment_constants
{
    double he_h;
    double n2_h;
    double he_a;
    double he_b;
    double n2_a;
    double n2_b;
};

struct compartment_state
{
    double he_p;
    double n2_p;
};

double schreiner(double pt0,
                 double palv0,
                 double r,
                 double t,
                 double half_val);
double haldane(double pt0,
               double palv0,
               double t,
               double half_val);


#define ZH_L12_NR_COMPARTMENTS 16
extern const struct compartment_constants zh_l12[];

#define WATER_VAPOR_PRESSURE 0.0627f
#define CO2_PRESSURE 0.0534f
#define SCHREINER_RQ 0.8f
#define USNAVY_RQ 0.9f
#define BUHLMANN_RQ 1.0f
double ventilation(double pamb,
                   double rq,
                   double ig_ratio);

double compartment_mvalue(const struct compartment_constants *constants,
                          struct compartment_state *compt);
void compartment_stagnate(const struct compartment_constants *constants,
                          struct compartment_state *cur,
                          struct compartment_state *end,
                          double p_ambient,
                          double time,
                          double rq,
                          double n2_ratio, double he_ratio);
void compartment_descend(const struct compartment_constants *constants,
                         struct compartment_state *cur,
                         struct compartment_state *end,
                         double p_ambient,
                         double rate,
                         double time,
                         double rq,
                         double n2_ratio, double he_ratio);

#endif /* _BUHLMANN_H_ */