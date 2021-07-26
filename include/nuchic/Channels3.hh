// Channel_Generator_UniV
#include "PHASIC++/Channels/Channel_Elements.H"
#include "nuchic/Mapper.hh"

using namespace PHASIC;
using namespace ATOOLS;

namespace PHASIC {
  class C3_0 : public nuchic::Mapper<Vec4D> {
    constexpr static double m_salpha=0.9,m_thexp=0.9;
  public:
    double   GenerateWeight(std::vector<Vec4D> *, std::vector<double> &) const override;
    void   GeneratePoint(std::vector<Vec4D> *,const std::vector<double> &) const override;
  };
  class C3_1 : public nuchic::Mapper<Vec4D> {
    constexpr static double m_salpha=0.9,m_thexp=0.9;
  public:
    double   GenerateWeight(std::vector<Vec4D> *, std::vector<double> &) const override;
    void   GeneratePoint(std::vector<Vec4D> *,const std::vector<double> &) const override;
  };
  class C3_2 : public nuchic::Mapper<Vec4D> {
    constexpr static double m_salpha=0.9,m_thexp=0.9;
    constexpr static double m_amct=1.,m_alpha=0.9,m_ctmax=1.,m_ctmin=-1.;
  public:
    double   GenerateWeight(std::vector<Vec4D> *, std::vector<double> &) const override;
    void   GeneratePoint(std::vector<Vec4D> *,const std::vector<double> &) const override;
  };
  class C3_3 : public nuchic::Mapper<Vec4D> {
    constexpr static double m_salpha=0.9,m_thexp=0.9;
    constexpr static double m_amct=1.,m_alpha=0.9,m_ctmax=1.,m_ctmin=-1.;
  public:
    double   GenerateWeight(std::vector<Vec4D> *, std::vector<double> &) const override;
    void   GeneratePoint(std::vector<Vec4D> *,const std::vector<double> &) const override;
  };
  class C3_4 : public nuchic::Mapper<Vec4D> {
    constexpr static double m_salpha=0.9,m_thexp=0.9;
    constexpr static double m_amct=1.,m_alpha=0.9,m_ctmax=1.,m_ctmin=-1.;
  public:
    double   GenerateWeight(std::vector<Vec4D> *,std::vector<double> &) const override;
    void   GeneratePoint(std::vector<Vec4D> *,const std::vector<double> &) const override;
  };
  class C3_5 : public nuchic::Mapper<Vec4D> {
    constexpr static double m_salpha=0.9,m_thexp=0.9;
    constexpr static double m_amct=1.,m_alpha=0.9,m_ctmax=1.,m_ctmin=-1.;
  public:
    double   GenerateWeight(std::vector<Vec4D> *, std::vector<double> &) const override;
    void   GeneratePoint(std::vector<Vec4D> *,const std::vector<double> &) const override;
  };
  class C3_6 : public nuchic::Mapper<Vec4D> {
    constexpr static double m_salpha=0.9,m_thexp=0.9;
    constexpr static double m_amct=1.,m_alpha=0.9,m_ctmax=1.,m_ctmin=-1.;
  public:
    double   GenerateWeight(std::vector<Vec4D> *, std::vector<double> &) const override;
    void   GeneratePoint(std::vector<Vec4D> *,const std::vector<double> &) const override;
  };
  class C3_7 : public nuchic::Mapper<Vec4D> {
    constexpr static double m_salpha=0.9,m_thexp=0.9;
    constexpr static double m_amct=1.,m_alpha=0.9,m_ctmax=1.,m_ctmin=-1.;
  public:
    double   GenerateWeight(std::vector<Vec4D> *, std::vector<double> &) const override;
    void   GeneratePoint(std::vector<Vec4D> *,const std::vector<double> &) const override;
  };
}
