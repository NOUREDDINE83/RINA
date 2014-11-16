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

#include <FlowTableItem.h>

FlowTableItem::FlowTableItem(Flow* flow, FABase* fa, RMTQueue* inQ, RMTQueue* outQ, std::string gateName)
:   flow(flow), fa(fa), rmtInputQueue(inQ), rmtOutputQueue(outQ), gateName(gateName)
{
}

FlowTableItem::~FlowTableItem() {

}

std::string FlowTableItem::info() const {
    std::ostringstream os;

    if (flow != NULL)
    {
        os << flow->info() << endl;
    }
    if (fa != NULL)
    {
        os << "FA path: " << fa->getFullPath() << "\n";
    }
    if (rmtOutputQueue != NULL)
    {
        os << "output RMT queue: " << rmtOutputQueue->getName() << "\n";
    }
    if (rmtInputQueue != NULL)
    {
        os << "input RMT queue: " << rmtInputQueue->getName();
    }
    return os.str();
}


std::ostream& operator <<(std::ostream& os, const FlowTableItem& cte) {
    return os << cte.info();
}

Flow* FlowTableItem::getFlow() const
{
    return flow;
}


FABase* FlowTableItem::getFaBase() const
{
    return fa;
}


RMTQueue* FlowTableItem::getRmtInputQueue() const
{
    return rmtInputQueue;
}

void FlowTableItem::setRmtInputQueue(RMTQueue* queue)
{
    this->rmtInputQueue = queue;
}

RMTQueue* FlowTableItem::getRmtOutputQueue() const
{
    return rmtOutputQueue;
}

void FlowTableItem::setRmtOutputQueue(RMTQueue* queue)
{
    this->rmtOutputQueue = queue;
}

std::string FlowTableItem::getGateName() const
{
    return gateName;
}


