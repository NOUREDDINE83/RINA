//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "APN.h"

APN::APN() {
    this->name = "";
}

APN::APN(std::string nam) {
    this->name = nam;
}


APN::~APN() {
    this->name = "";
}

const std::string& APN::getName() const {
    return name;
}

void APN::setName(const std::string& name) {
    this->name = name;
}

std::string APN::info() const{
    std::stringstream os;
    os << this->getName();
    return os.str();
}

//Free function
std::ostream& operator<< (std::ostream& os, const APN& apn) {
    return os << apn.info();
}