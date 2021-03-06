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

#ifndef ENROLLMENTNOTIFIERBASE_H_
#define ENROLLMENTNOTIFIERBASE_H_

//Standard libraries
#include <omnetpp.h>
//RINASim libraries
#include "CDAPProcessingBase.h"
#include "ExternConsts.h"
#include "RINASignals.h"
#include "EnrollmentObj.h"
#include "OperationObj.h"

class EnrollmentNotifierBase : public cSimpleModule, public CDAPProcessingBase {
  public:

    virtual void sendStartEnrollmentRequest(EnrollmentObj* obj) = 0;
    virtual void sendStartEnrollmentResponse(EnrollmentObj* obj) = 0;
    virtual void sendStopEnrollmentRequest(EnrollmentObj* obj) = 0;
    virtual void sendStopEnrollmentResponse(EnrollmentObj* obj) = 0;
    virtual void sendStartOperationRequest(OperationObj* obj) = 0;
    virtual void sendStartOperationResponse(OperationObj* obj) = 0;
    virtual void sendCACE(CDAPMessage* msg) = 0;

    //CDAPProcessingBase interface
    virtual bool isMessageProcessable(CDAPMessage* msg);
    virtual void receiveMessage(CDAPMessage* msg);
    virtual void signalizeMessage(CDAPMessage* msg) = 0;

};

#endif /* ENROLLMENTNOTIFIERBASE_H_ */
