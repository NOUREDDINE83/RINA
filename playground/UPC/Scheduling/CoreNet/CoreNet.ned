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

package rina.playground.UPC.Scheduling.CoreNet;


import ned.DatarateChannel;
import rina.src.CS.HostNAP;
import rina.src.Other.Infection.InfectedRouter;
import rina.src.CS.InteriorRouterNInt;

import rina.src.Other.Infection.IListener;
import rina.src.DAF.AE.AEConstant.AEConstantListener;

network CoreNet
{
    @display("bgb=838,510");
    submodules:
        r1: InfectedRouter {
            @display("p=117,112");
        }
        r2: InfectedRouter {
            @display("p=156,301");
        }
        r3: InfectedRouter {
            @display("p=215,202");
        }
        r4: InfectedRouter {
            @display("p=395,231");
        }
        r5: InfectedRouter {
            @display("p=441,364");
        }
        r6: InfectedRouter {
            @display("p=518,192");
        }
        r7: InfectedRouter {
            @display("p=599,311");
        }
        r8: InfectedRouter {
            @display("p=629,131");
        }
        r9: InfectedRouter {
            @display("p=715,221");
        }
        ra: InfectedRouter {
            @display("p=767,105");
        }
        B2: InfectedRouter {
            @display("p=321,286");
        }
        listener: IListener {
            @display("p=240,415");
        }
    connections:
        r1.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 6.5ms; } <--> r2.medium++;
        r1.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 4.5ms; } <--> r3.medium++;
        r1.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 12ms; } <--> r6.medium++;
        r2.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 6.0ms; } <--> r3.medium++;
        r2.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 6.5ms; } <--> r5.medium++;
        r3.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 5.0ms; } <--> r4.medium++;
        r4.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 4.5ms; } <--> r5.medium++;
        r4.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 5.0ms; } <--> r6.medium++;
        r5.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 5.0ms; } <--> r7.medium++;
        r6.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 4.0ms; } <--> r7.medium++;
        r6.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 5.0ms; } <--> r8.medium++;
        r7.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 4.0ms; } <--> r9.medium++;
        r8.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 4.0ms; } <--> r9.medium++;
        r8.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 4.0ms; } <--> ra.medium++;
        r9.medium++ <--> DatarateChannel {  datarate = 10Gbps; delay = 4.5ms; } <--> ra.medium++;

}
