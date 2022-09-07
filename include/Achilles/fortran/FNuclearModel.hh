#ifndef FNUCLEAR_MODEL_HH
#define FNUCLEAR_MODEL_HH

#include "Achilles/NuclearModel.hh"

extern "C" {
    void RegisterAll();
    void ListModels();
    bool CreateModel(char*);
    bool InitModel(char*);
    void CleanUpEvent(std::complex<double>**, int*);
    void CleanUpModel();
    int GetMode();
    char* GetName();
    void GetCurrents(long *pids_in, long *pids_out, achilles::FourVector *pin, size_t nin, size_t nout,          
                     achilles::FourVector *q, std::complex<double>* ff, size_t nff,
                     std::complex<double>* current, size_t nspins, size_t nlorentz);
    // bool GetAllowedStates(achilles::Process_Info*);
    // size_t GetNSpins();
    // bool FillNucleus(achilles::Event*, const double*, size_t);
}

namespace achilles {

class FortranModel : public NuclearModel, RegistrableNuclearModel<FortranModel> {
    public:
        FortranModel(const YAML::Node&, const YAML::Node&, const std::shared_ptr<Nucleus>&, FormFactorBuilder&);
        ~FortranModel() override { CleanUpModel(); }
        
        NuclearMode Mode() const override { 
            return static_cast<NuclearMode>(GetMode());
        }
        std::string PhaseSpace() const override {
            char *name = GetName();
            auto tmp = std::string(name);
            delete name;
            return tmp;
        }
        std::vector<Currents> CalcCurrents(const Event&, const std::vector<FFInfoMap>&) const override;
        // void AllowedStates(Process_Info &info) override {
        //     GetAllowedStates(&info);
        //     m_info = info;
        // }
        // size_t NSpins() const override { return GetNSpins(); }
        // bool FillNucleus(Event &event, const std::vector<double> &xsecs) const override { 
        //     return ::FillNucleus(&event, xsecs.data(), xsecs.size());
        // }

        // Required factory methods
        static std::unique_ptr<NuclearModel> Construct(const YAML::Node&, const std::shared_ptr<Nucleus>&);
        static std::string Name() { return "FortranModel"; }

        // Method needed to register fortran models at start-up
        static void RegisterModels() { RegisterAll(); }
        static void DisplayModels() { 
            fmt::print("Available Fortran nuclear models:\n");
            ListModels();
        }
};

}

#endif
