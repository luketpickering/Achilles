#include "nuchic/Channels3.hh"

using namespace PHASIC;
using namespace ATOOLS;

void C3_0::GeneratePoint(std::vector<Vec4D> * p,const std::vector<double> & ran) const
{
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  Vec4D  p34;
  double s34 = CE.MasslessPropMomenta(m_salpha,s34_min,s34_max,ran[0]);
  CE.Isotropic2Momenta(p[0]+p[1],s2,s34,p[2],p34,ran[1],ran[2]);
  CE.Isotropic2Momenta(p34,s3,s4,p[3],p[4],ran[3],ran[4]);
}

double C3_0::GenerateWeight(std::vector<Vec4D> * p,Cut_Data * cuts, std::vector<double> & rans) const
{
  double wt = 1.;
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  wt *= CE.MasslessPropWeight(m_salpha,s34_min,s34_max,dabs((p[3]+p[4]).Abs2()),rans[0]);
  wt *= CE.Isotropic2Weight(p[2],p[3]+p[4],rans[1],rans[2]);
  wt *= CE.Isotropic2Weight(p[3],p[4],rans[3],rans[4]);
  if (wt!=0.) wt = 1.0/wt/pow(2.*M_PI,3*3.-4.);

  weight = wt;
  return weight
}

void C3_1::GeneratePoint(std::vector<Vec4D> * p,const std::vector<double> & ran) const
{
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  Flavour fl34 = Flavour((kf_code)(23));
  Vec4D  p34;
  double s34 = CE.MassivePropMomenta(fl34.Mass(),fl34.Width(),1,s34_min,s34_max,ran[0]);
  CE.Isotropic2Momenta(p[0]+p[1],s2,s34,p[2],p34,ran[1],ran[2]);
  CE.Isotropic2Momenta(p34,s3,s4,p[3],p[4],ran[3],ran[4]);
}

double C3_1::GenerateWeight(std::vector<Vec4D> * p,std::vector<double> & rans) const
{
  double wt = 1.;
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  Flavour fl34 = Flavour((kf_code)(23));
  Vec4D  p34 = p[3]+p[4];
  wt *= CE.MassivePropWeight(fl34.Mass(),fl34.Width(),1,s34_min,s34_max,dabs((p[3]+p[4]).Abs2()),rans[0]);
  wt *= CE.Isotropic2Weight(p[2],p[3]+p[4],rans[1],rans[2]);
  wt *= CE.Isotropic2Weight(p[3],p[4],rans[3],rans[4]);
  if (wt!=0.) wt = 1.0/wt/pow(2.*M_PI,3*3.-4.);

  weight = wt;
  return weight
}

void C3_2::GeneratePoint(std::vector<Vec4D> * p,const std::vector<double> & ran) const
{
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  Vec4D  p34;
  double s34 = CE.MasslessPropMomenta(m_salpha,s34_min,s34_max,ran[0]);
  CE.TChannelMomenta(p[0],p[1],p[2],p34,s2,s34,0.,m_alpha,m_ctmax,m_ctmin,m_amct,0,ran[1],ran[2]);
  CE.TChannelMomenta(p[0]-p[2],p[1],p[4],p[3],s4,s3,0.,m_alpha,1.,-1.,m_amct,0,ran[3],ran[4]);
}

double C3_2::GenerateWeight(std::vector<Vec4D> * p,std::vector<double> & rans) const
{
  double wt = 1.;
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  wt *= CE.MasslessPropWeight(m_salpha,s34_min,s34_max,dabs((p[3]+p[4]).Abs2()),rans[0]);
  wt *= CE.TChannelWeight(p[0],p[1],p[2],p[3]+p[4],0.,m_alpha,m_ctmax,m_ctmin,m_amct,0,rans[1],rans[2]);
  wt *= CE.TChannelWeight(p[0]-p[2],p[1],p[4],p[3],0.,m_alpha,1.,-1.,m_amct,0,rans[3],rans[4]);
  if (wt!=0.) wt = 1.0/wt/pow(2.*M_PI,3*3.-4.);

  weight = wt;
  return weight
}

void C3_3::GeneratePoint(std::vector<Vec4D> * p,const std::vector<double> & ran) const
{
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  Vec4D  p34;
  double s34 = CE.MasslessPropMomenta(m_salpha,s34_min,s34_max,ran[0]);
  double tmass201 = Flavour((kf_code)(23)).Mass();
  CE.TChannelMomenta(p[0],p[1],p[2],p34,s2,s34,tmass201,m_alpha,m_ctmax,m_ctmin,m_amct,0,ran[1],ran[2]);
  CE.TChannelMomenta(p[0]-p[2],p[1],p[4],p[3],s4,s3,0.,m_alpha,1.,-1.,m_amct,0,ran[3],ran[4]);
}

double C3_3::GenerateWeight(std::vector<Vec4D> * p, std::vector<double> & rans) const
{
  double wt = 1.;
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  wt *= CE.MasslessPropWeight(m_salpha,s34_min,s34_max,dabs((p[3]+p[4]).Abs2()),rans[0]);
  double tmass201 = Flavour((kf_code)(23)).Mass();
  wt *= CE.TChannelWeight(p[0],p[1],p[2],p[3]+p[4],tmass201,m_alpha,m_ctmax,m_ctmin,m_amct,0,rans[1],rans[2]);
  wt *= CE.TChannelWeight(p[0]-p[2],p[1],p[4],p[3],0.,m_alpha,1.,-1.,m_amct,0,rans[3],rans[4]);
  if (wt!=0.) wt = 1./wt/pow(2.*M_PI,3*3.-4.);

  weight = wt;
  return weight
}

void C3_4::GeneratePoint(std::vector<Vec4D> * p,const std::vector<double> & ran) const
{
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  Vec4D  p34;
  double s34 = CE.MasslessPropMomenta(m_salpha,s34_min,s34_max,ran[0]);
  CE.TChannelMomenta(p[0],p[1],p[2],p34,s2,s34,0.,m_alpha,m_ctmax,m_ctmin,m_amct,0,ran[1],ran[2]);
  CE.TChannelMomenta(p[0]-p[2],p[1],p[3],p[4],s3,s4,0.,m_alpha,1.,-1.,m_amct,0,ran[3],ran[4]);
}

double C3_4::GenerateWeight(std::vector<Vec4D> * p, std::vector<double> & rans) const
{
  double wt = 1.;
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  wt *= CE.MasslessPropWeight(m_salpha,s34_min,s34_max,dabs((p[3]+p[4]).Abs2()),rans[0]);
  wt *= CE.TChannelWeight(p[0],p[1],p[2],p[3]+p[4],0.,m_alpha,m_ctmax,m_ctmin,m_amct,0,rans[1],rans[2]);
  wt *= CE.TChannelWeight(p[0]-p[2],p[1],p[3],p[4],0.,m_alpha,1.,-1.,m_amct,0,rans[3],rans[4]);
  if (wt!=0.) wt = 1.0/wt/pow(2.*M_PI,3*3.-4.);

  weight = wt;
  return weight
}

void C3_5::GeneratePoint(std::vector<Vec4D> * p,const std::vector<double> & ran) const
{
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  Vec4D  p34;
  double s34 = CE.MasslessPropMomenta(m_salpha,s34_min,s34_max,ran[0]);
  double tmass201 = Flavour((kf_code)(23)).Mass();
  CE.TChannelMomenta(p[0],p[1],p[2],p34,s2,s34,tmass201,m_alpha,m_ctmax,m_ctmin,m_amct,0,ran[1],ran[2]);
  CE.TChannelMomenta(p[0]-p[2],p[1],p[3],p[4],s3,s4,0.,m_alpha,1.,-1.,m_amct,0,ran[3],ran[4]);
}

double C3_5::GenerateWeight(std::vector<Vec4D> * p, std::vector<double> & rans) const
{
  double wt = 1.;
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  wt *= CE.MasslessPropWeight(m_salpha,s34_min,s34_max,dabs((p[3]+p[4]).Abs2()),rans[0]);
  double tmass201 = Flavour((kf_code)(23)).Mass();
  wt *= CE.TChannelWeight(p[0],p[1],p[2],p[3]+p[4],tmass201,m_alpha,m_ctmax,m_ctmin,m_amct,0,rans[1],rans[2]);
  wt *= CE.TChannelWeight(p[0]-p[2],p[1],p[3],p[4],0.,m_alpha,1.,-1.,m_amct,0,rans[3],rans[4]);
  if (wt!=0.) wt = 1.0/wt/pow(2.*M_PI,3*3.-4.);

  weight = wt;
  return weight
}

void C3_6::GeneratePoint(std::vector<Vec4D> * p,const std::vector<double> & ran) const
{
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  Vec4D  p34;
  double s34 = CE.MasslessPropMomenta(m_salpha,s34_min,s34_max,ran[0]);
  CE.TChannelMomenta(p[0],p[1],p34,p[2],s34,s2,0.,m_alpha,m_ctmax,m_ctmin,m_amct,0,ran[1],ran[2]);
  CE.Isotropic2Momenta(p34,s3,s4,p[3],p[4],ran[3],ran[4]);
}

double C3_6::GenerateWeight(std::vector<Vec4D> * p, std::vector<double> & rans) const
{
  double wt = 1.;
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  wt *= CE.MasslessPropWeight(m_salpha,s34_min,s34_max,dabs((p[3]+p[4]).Abs2()),rans[0]);
  wt *= CE.TChannelWeight(p[0],p[1],p[3]+p[4],p[2],0.,m_alpha,m_ctmax,m_ctmin,m_amct,0,rans[1],rans[2]);
  wt *= CE.Isotropic2Weight(p[3],p[4],rans[3],rans[4]);
  if (wt!=0.) wt = 1.0/wt/pow(2.*M_PI,3*3.-4.);

  weight = wt;
  return weight
}

void C3_7::GeneratePoint(std::vector<Vec4D> * p,const std::vector<double> & ran) const
{
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  Flavour fl34 = Flavour((kf_code)(23));
  Vec4D  p34;
  double s34 = CE.MassivePropMomenta(fl34.Mass(),fl34.Width(),1,s34_min,s34_max,ran[0]);
  CE.TChannelMomenta(p[0],p[1],p34,p[2],s34,s2,0.,m_alpha,m_ctmax,m_ctmin,m_amct,0,ran[1],ran[2]);
  CE.Isotropic2Momenta(p34,s3,s4,p[3],p[4],ran[3],ran[4]);
}

double C3_7::GenerateWeight(std::vector<Vec4D> * p, std::vector<double> & rans) const
{
  double wt = 1.;
  double s34_max = sqr((p[0]+p[1]).Mass()-sqrt(s2));
  double s34_min = cuts->GetscutAmegic(std::string("34"));
  Flavour fl34 = Flavour((kf_code)(23));
  wt *= CE.MassivePropWeight(fl34.Mass(),fl34.Width(),1,s34_min,s34_max,dabs((p[3]+p[4]).Abs2()),rans[0]);
  wt *= CE.TChannelWeight(p[0],p[1],p[3]+p[4],p[2],0.,m_alpha,m_ctmax,m_ctmin,m_amct,0,rans[1],rans[2]);
  wt *= CE.Isotropic2Weight(p[3],p[4],rans[3],rans[4]);
  if (wt!=0.) wt = 1.0/wt/pow(2.*M_PI,3*3.-4.);

  weight = wt;
  return weight
}
