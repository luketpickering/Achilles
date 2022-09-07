#include "Achilles/ProcessInfo.hh"

size_t achilles::Process_Info::Multiplicity() const {
    return ids.size() + state.first.size() + state.second.size();
}

std::vector<double> achilles::Process_Info::Masses() const {
    std::vector<double> masses;

    // Get Hadronic current masses
    for(size_t i = 0; i < state.second.size(); ++i) {
        masses.push_back(pow(ParticleInfo(state.second[i]).Mass(), 2));
    }

    // Get Leptonic current masses
    for(size_t i = 1; i < ids.size(); ++i) {
        masses.push_back(pow(ParticleInfo(ids[i]).Mass(), 2));
    }

    return masses;
}

std::vector<long> achilles::Process_Info::Ids() const {
    std::vector<long> ids_;

    // Get initial hadronic ids
    for(size_t i = 0; i < state.first.size(); ++i)
        ids_.push_back(state.first[i].AsInt());

    // Get inital lepton id
    ids_.push_back(ids[0].AsInt());

    // Get remaining hadronic ids
    for(size_t i = 0; i < state.second.size(); ++i)
        ids_.push_back(state.second[i].AsInt());

    // Get remaining leptonic ids
    for(size_t i = 1; i < ids.size(); ++i)
        ids_.push_back(ids[i].AsInt());

    return ids_;
}
