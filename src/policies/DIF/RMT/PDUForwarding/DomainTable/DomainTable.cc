#include <DomainTable/DomainTable.h>



#include <Utils.h>
#include <sstream>

namespace DomainTable {

Register_Class(DomainTable);

using namespace std;


// Lookup function, return a list of RMTPorts to forward a PDU/Address+qos.
vector<RMTPort * > DomainTable::lookup(const PDU * pdu){
    return lookup(pdu->getDstAddr(), pdu->getConnId().getQoSId());
}

vector<RMTPort * > DomainTable::lookup(const Address &dst, const unsigned short &qos){
    vector<RMTPort* > ret;

    pAddr pa = parseAddr(dst.getIpcAddress().getName());
    if(table[pa.domain].entries.find(pa.addr) != table[pa.domain].entries.end()){
        ret.push_back(table[pa.domain].entries[pa.addr]);
        return ret;
    }

    return ret;
}

// Returns a representation of the Forwarding Knowledge
string DomainTable::toString(){
    std::ostringstream os;

    os << this->getName()<<endl;
    for(FWDTableIt tIt = table.begin(); tIt != table.end(); tIt++){
        os << "\t Domain : \"" <<tIt->first<<"\""<<endl;
        for(s2PortIt qIt = tIt->second.entries.begin();
                qIt != tIt->second.entries.end();
                qIt++){
            os << "\t\t->(" << qIt->first << " , "<<qIt->second->getFullPath()<<")" <<endl;
        }
    }

    return os.str();
}

//Insert/Remove a domain
void DomainTable::addDomain(const string &domain){
    domains.push_back(domain);
    if(domain == ""){
        table[""].len = 0;
    } else {
        table[domain].len = split(domain, '.').size();
    }
}
void DomainTable::removeDomain(const string &domain){
    for(sListIt it = domains.begin(); it!= domains.end(); it++){
        if(*it == domain){
            domains.erase(it);
            break;
        }
    }
    domains.push_back(domain);
    table.erase(domain);
}

//Insert/Remove an entry
void DomainTable::insert(const string &domain, const string &addr, RMTPort * port){
    table[domain].entries[addr] = port;
}
void DomainTable::remove(const string &domain, const string &addr){
    table[domain].entries.erase(addr);
}

pAddr DomainTable::parseAddr(const string &addr){
    for(sListIt it = domains.begin(); it!= domains.end(); it++){
        if(isPrefix(*it, addr)){
            unsigned short len = table[*it].len;
            vector<string> sep = split(addr, '.');
            if(sep.size() <= len) {
                return pAddr(*it, "");
            } else {
                return pAddr(*it, sep[len]);
            }
        }
    }
    return pAddr("", addr);
}

// Called after initialize
void DomainTable::onIni(){}

void DomainTable::finish(){
    EV << toString() <<endl;
}

}
