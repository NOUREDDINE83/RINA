// The MIT License (MIT)
//
// Copyright (c) 2014-2016 Brno University of Technology, PRISTINE project
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


package rina.src.Other.Infection;

import rina.src.DAF.AE.AEVideo.AEVideo;
import rina.src.DAF.DA.DIFAllocator;
import rina.src.DIF.IPCProcess;

module InfectedRouterGW
{
    parameters:
        @display("i=abstract/switch;bgb=391,325");
        @node;

    gates:
        inout medium[];
        inout mediumGW;

    submodules:
        GWIpc: IPCProcess {
            @display("p=211,65;i=,#FFB000");
            relay = true;
        }
        bottomGW: IPCProcess {
            @display("p=211,179,r,150");
            relay = false;
            onWire = true;
        }

        ipcProcess[sizeof(medium)]: IPCProcess {
            @display("p=104,245,r,150");
            relay = false;
        }
        relayIpc: IPCProcess {
            @display("p=104,147;i=,#FFB000");
            relay = true;
        }
        difAllocator: DIFAllocator {
            @display("p=104,53");
        }
        infection: Infection {
            @display("p=296,254");
            infectedIPC = default("relayIpc");
        }
    connections allowunconnected:

        
        // Every IPC Process is connected to its medium and the Relay IPC.
        for i=0..sizeof(medium)-1 {
            relayIpc.southIo++ <--> ipcProcess[i].northIo++;
            ipcProcess[i].southIo++ <--> medium[i];
        }
        
        bottomGW.southIo++ <--> mediumGW;
        GWIpc.southIo++ <--> bottomGW.northIo++;
        GWIpc.southIo++ <--> relayIpc.northIo++;
}
