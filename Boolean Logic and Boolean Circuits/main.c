/*
 * File: main.c
 * Creator: George Ferguson
 * Created: Mon Nov 28 14:11:17 2016
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Circuit.h"

// static Circuit and3_Circuit() {
//     char *title = "Two AND gates connected to make a 3-input AND circuit";
//     // Create the inputs
//     int NINPUTS = 3;
//     Boolean x = new_Boolean(false);
//     Boolean y = new_Boolean(false);
//     Boolean z = new_Boolean(false);
//     Boolean* inputs = new_Boolean_array(NINPUTS);
//     inputs[0] = x;
//     inputs[1] = y;
//     inputs[2] = z;

//     // Create the outputs
//     int NOUTPUTS = 1;
//     Boolean result = new_Boolean(false);
//     Boolean* outputs = new_Boolean_array(NOUTPUTS);
//     outputs[0] = result;

//     // Create the gates
//     int NGATES = 2;
//     Gate A1 = new_AndGate();
//     Gate A2 = new_AndGate();
//     Gate* gates = new_Gate_array(NGATES);
//     gates[0] = A1;
//     gates[1] = A2;

//     // Create the circuit
//     Circuit circuit = new_Circuit(title,
// 				  NINPUTS, inputs,
// 				  NOUTPUTS, outputs,
// 				  NGATES, gates);

//     // Connect the gates in the circuit
//     Circuit_connect(circuit, x, Gate_getInput(A1, 0));
//     Circuit_connect(circuit, y, Gate_getInput(A1, 1));
//     Boolean x_and_y = Gate_getOutput(A1);

//     Circuit_connect(circuit, x_and_y, Gate_getInput(A2, 0));
//     Circuit_connect(circuit, z, Gate_getInput(A2, 1));
//     Boolean x_and_y_and_z = Gate_getOutput(A2);

//     Circuit_connect(circuit, x_and_y_and_z, result);

//     // Done!
//     return circuit;
// }

// You should not use this function in your project.
// It is here to show you how to get and set values in a circuit using the API.
// See the project description for what you are required to do.
// Go to study session if you have questions about how to do it.
// static void test3In1Out(Circuit circuit, bool in0, bool in1, bool in2) {
//     Circuit_setInput(circuit, 0, in0);
//     Circuit_setInput(circuit, 1, in1);
//     Circuit_setInput(circuit, 2, in2);
//     Circuit_update(circuit);
//     printf("%s %s %s -> %s\n",
// 	   Boolean_toString(Circuit_getInput(circuit, 0)),
// 	   Boolean_toString(Circuit_getInput(circuit, 1)),
// 	   Boolean_toString(Circuit_getInput(circuit, 2)),
// 	   Boolean_toString(Circuit_getOutput(circuit, 0)));
// }


static Circuit circuit_a(){
    
    char *title = "Circuit A: two inverters and one AND gate with 2 inputs and 1 output";
    
    // Create the inputs
    int NINPUTS = 2;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;

    // Create the outputs
    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the gates
    int NGATES = 3;
    Gate A1 = new_Inverter();
    Gate A2 = new_Inverter();
    Gate A3 = new_AndGate();
    Gate* gates = new_Gate_array(NGATES);
    gates[0] = A1;
    gates[1] = A2;
    gates[2] = A3;

    // Create the circuit
    Circuit circuit = new_Circuit(title,
				  NINPUTS, inputs,
				  NOUTPUTS, outputs,
				  NGATES, gates);
    
    
    // Connect the gates in the circuit
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A2, 0));

    Boolean not_x = Gate_getOutput(A1);
    Boolean not_y = Gate_getOutput(A2);

    Circuit_connect(circuit, not_x, Gate_getInput(A3, 0));
    Circuit_connect(circuit, not_y, Gate_getInput(A3, 1));
    Boolean not_x_and_not_y = Gate_getOutput(A3);

    Circuit_connect(circuit, not_x_and_not_y, result);

    // Done!
    return circuit;
}

static Circuit circuit_b(){
    
    char *title = "Circuit B: three NAND gates with 2 inputs and 1 output";
    
    // Create the inputs
    int NINPUTS = 2;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;

    // Create the outputs
    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the gates
    int NGATES = 6;
    Gate A1 = new_AndGate();
    Gate A2 = new_AndGate();
    Gate A3 = new_Inverter();
    Gate A4 = new_Inverter();
    Gate A5 = new_AndGate();
    Gate A6 = new_Inverter();

    Gate* gates = new_Gate_array(NGATES);
    gates[0] = A1;
    gates[1] = A2;
    gates[2] = A3;
    gates[3] = A4;
    gates[4] = A5;
    gates[5] = A6;

    // Create the circuit
    Circuit circuit = new_Circuit(title,
				  NINPUTS, inputs,
				  NOUTPUTS, outputs,
				  NGATES, gates);
    
    
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A1, 1));
    Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A3, 0));
    Boolean nand_1 = Gate_getOutput(A3);
    Circuit_connect(circuit, x, Gate_getInput(A2, 0));
    Circuit_connect(circuit, y, Gate_getInput(A2, 1));
    Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A4, 0));
    Boolean nand_2 = Gate_getOutput(A4);
    Circuit_connect(circuit, nand_1, Gate_getInput(A5, 0));
    Circuit_connect(circuit, nand_2, Gate_getInput(A5, 1));
    Circuit_connect(circuit, Gate_getOutput(A5), Gate_getInput(A6, 0)); 
    Circuit_connect(circuit, Gate_getOutput(A6), result);
    return circuit;
}

static Circuit circuit_c(){
    
    char *title = "Circuit C: two AND gates, two OR gates, and 1 inverter with 3 inputs and 1 output";
        int NINPUTS = 3;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean z = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;
    inputs[2] = z;

    // Create the outputs
    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the gates
    int NGATES = 5;
    Gate A1 = new_AndGate();
    Gate A2 = new_OrGate();
    Gate A3 = new_Inverter();
    Gate A4 = new_AndGate();
    Gate A5 = new_OrGate();

    Gate* gates = new_Gate_array(NGATES);
    gates[0] = A1;
    gates[1] = A2;
    gates[2] = A3;
    gates[3] = A4;
    gates[4] = A5;

    // Create the circuit
    Circuit circuit = new_Circuit(title,
				  NINPUTS, inputs,
				  NOUTPUTS, outputs,
				  NGATES, gates);
    
    
    // Connect the gates in the circuit
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A1, 1));

    Boolean x_and_y = Gate_getOutput(A1);

    Circuit_connect(circuit, x, Gate_getInput(A2, 0));
    Circuit_connect(circuit, y, Gate_getInput(A2, 1));

    Boolean x_or_y = Gate_getOutput(A2);
    Circuit_connect(circuit, z, Gate_getInput(A3, 0));
    Boolean not_z = Gate_getOutput(A3);
    Circuit_connect(circuit, x_or_y, Gate_getInput(A4, 0));
    Circuit_connect(circuit, not_z, Gate_getInput(A4, 1));
    Boolean x_or_y_AND_not_z = Gate_getOutput(A4);
    Circuit_connect(circuit, x_and_y, Gate_getInput(A5, 0));
    Circuit_connect(circuit, x_or_y_AND_not_z, Gate_getInput(A5, 1));
    Boolean A5_res = Gate_getOutput(A5);
    Circuit_connect(circuit, A5_res, result);
    return circuit;
}

static Circuit circuit_f () {

    char *title = "EXTRA CREDIT: Circuit F";

    int NINPUTS = 3;
	Boolean a = new_Boolean(false);
	Boolean b = new_Boolean(false);
	Boolean c = new_Boolean(false);
	Boolean* inputs = new_Boolean_array(NINPUTS);
	inputs[0] = a;
	inputs[1] = b;
	inputs[2] = c;

    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    int NGATES = 14;
	Gate* gates = new_Gate_array(NGATES);
	Gate N1 = new_Inverter();
	Gate N2 = new_Inverter();
	Gate N3 = new_Inverter();
	Gate A1 = new_AndGate();
	Gate A2 = new_AndGate();
	Gate A3 = new_AndGate();
	Gate A4 = new_AndGate();
    Gate A5 = new_AndGate();
	Gate A6 = new_AndGate();
	Gate A7 = new_AndGate();
	Gate A8 = new_AndGate();
	Gate OR1 = new_OrGate();
	Gate OR2 = new_OrGate();
	Gate OR3 = new_OrGate();

	gates[0] = N1;
	gates[1] = N2;
	gates[2] = N3;
	gates[3] = A1;
	gates[4] = A2;
	gates[5] = A3;
	gates[6] = A4;
    gates[7] = A5;
	gates[8] = A6;
	gates[9] = A7;
	gates[10] = A8;
	gates[11] = OR1;
	gates[12] = OR2;
	gates[13] = OR3;

    Circuit circuit = new_Circuit(title,
				  NINPUTS, inputs,
				  NOUTPUTS, outputs,
				  NGATES, gates);

	Circuit_connect(circuit, a, Gate_getInput(N1, 0));
	Circuit_connect(circuit, b, Gate_getInput(N2, 0));
	Circuit_connect(circuit, c, Gate_getInput(N3, 0));
	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A1, 0));
	Circuit_connect(circuit, b, Gate_getInput(A1, 1));
    Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A2, 0));
    Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A2, 1));
	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A3, 0));
	Circuit_connect(circuit, b, Gate_getInput(A3, 1));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(A4, 0));
	Circuit_connect(circuit, c, Gate_getInput(A4, 1));
	Circuit_connect(circuit, a, Gate_getInput(A5, 0));
	Circuit_connect(circuit, b, Gate_getInput(A5, 1));
	Circuit_connect(circuit, Gate_getOutput(A5), Gate_getInput(A6, 0));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A6, 1));
	Circuit_connect(circuit, a, Gate_getInput(A7, 0));
	Circuit_connect(circuit, b, Gate_getInput(A7, 1));
	Circuit_connect(circuit, Gate_getOutput(A7), Gate_getInput(A8, 0));
	Circuit_connect(circuit, c, Gate_getInput(A8, 1));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(OR1, 0));
	Circuit_connect(circuit, Gate_getOutput(A4), Gate_getInput(OR1, 1));
	Circuit_connect(circuit, Gate_getOutput(A6), Gate_getInput(OR2, 0));
	Circuit_connect(circuit, Gate_getOutput(A8), Gate_getInput(OR2, 1));
	Circuit_connect(circuit, Gate_getOutput(OR1), Gate_getInput(OR3, 0));
	Circuit_connect(circuit, Gate_getOutput(OR2), Gate_getInput(OR3, 1));
	Circuit_connect(circuit, Gate_getOutput(OR3), result);
	return circuit;
}

static Circuit circuit_g () {

    char *title = "EXTRA CREDIT: Circuit G";
    int NINPUTS = 3;
	Boolean a = new_Boolean(false);
	Boolean b = new_Boolean(false);
	Boolean c = new_Boolean(false);
	Boolean* inputs = new_Boolean_array(NINPUTS);
	inputs[0] = a;
	inputs[1] = b;
	inputs[2] = c;

    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    int NGATES = 14;
	Gate N1 = new_Inverter();
	Gate N2 = new_Inverter();
	Gate N3 = new_Inverter();
	Gate A1 = new_AndGate();
	Gate A2 = new_AndGate();
	Gate A3 = new_AndGate();
	Gate A4 = new_AndGate();
	Gate A5 = new_AndGate();
	Gate A6 = new_AndGate();
	Gate A7 = new_AndGate();
	Gate A8 = new_AndGate();
	Gate OR1 = new_OrGate();
	Gate OR2 = new_OrGate();
	Gate OR3 = new_OrGate();

	Gate* gates = new_Gate_array(NGATES);
	gates[0] = N1;
	gates[1] = N2;
	gates[2] = N3;
	gates[3] = A1;
	gates[4] = A2;
	gates[5] = A3;
	gates[6] = A4;
	gates[7] = A5;
	gates[8] = A6;
	gates[9] = A7;
	gates[10] = A8;
	gates[11] = OR1;
	gates[12] = OR2;
	gates[13] = OR3;

    Circuit circuit = new_Circuit(title,
				  NINPUTS, inputs,
				  NOUTPUTS, outputs,
				  NGATES, gates);

	Circuit_connect(circuit, a, Gate_getInput(N1, 0));
	Circuit_connect(circuit, b, Gate_getInput(N2, 0));
	Circuit_connect(circuit, c, Gate_getInput(N3, 0));
	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A1, 0));
	Circuit_connect(circuit, Gate_getOutput(N2), Gate_getInput(A1, 1));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A2, 0));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A2, 1));
	Circuit_connect(circuit, Gate_getOutput(N1), Gate_getInput(A3, 0));
	Circuit_connect(circuit, b, Gate_getInput(A3, 1));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(A4, 0));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A4, 1));
	Circuit_connect(circuit, a, Gate_getInput(A5, 0));
	Circuit_connect(circuit, Gate_getOutput(N2), Gate_getInput(A5, 1));
	Circuit_connect(circuit, Gate_getOutput(A5), Gate_getInput(A6, 0));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A6, 1));
	Circuit_connect(circuit, a, Gate_getInput(A7, 0));
	Circuit_connect(circuit, b, Gate_getInput(A7, 1));
	Circuit_connect(circuit, Gate_getOutput(A7), Gate_getInput(A8, 0));
	Circuit_connect(circuit, Gate_getOutput(N3), Gate_getInput(A8, 1));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(OR1, 0));
	Circuit_connect(circuit, Gate_getOutput(A4), Gate_getInput(OR1, 1));
	Circuit_connect(circuit, Gate_getOutput(A6), Gate_getInput(OR2, 0));
	Circuit_connect(circuit, Gate_getOutput(A8), Gate_getInput(OR2, 1));
	Circuit_connect(circuit, Gate_getOutput(OR1), Gate_getInput(OR3, 0));
	Circuit_connect(circuit, Gate_getOutput(OR2), Gate_getInput(OR3, 1));
	Circuit_connect(circuit, Gate_getOutput(OR3), result);

	return circuit;
}

// static void test_2in1out (Circuit circuit, bool in0, bool in1) {
//     Circuit_setInput(circuit, 0, in0);
//     Circuit_setInput(circuit, 1, in1);
//     Circuit_update(circuit);
//     printf("%s %s -> %s\n",
// 	   Boolean_toString(Circuit_getInput(circuit, 0)),
// 	   Boolean_toString(Circuit_getInput(circuit, 1)),
// 	   Boolean_toString(Circuit_getOutput(circuit, 0)));
// }

// static void test_3in1out (Circuit circuit, bool in0, bool in1, bool in2) {
//     Circuit_setInput(circuit, 0, in0);
//     Circuit_setInput(circuit, 1, in1);
//     Circuit_setInput(circuit, 2, in2);
//     Circuit_update(circuit);
//     printf("%s %s %s-> %s\n",
// 	   Boolean_toString(Circuit_getInput(circuit, 0)),
// 	   Boolean_toString(Circuit_getInput(circuit, 1)),
// 	   Boolean_toString(Circuit_getInput(circuit, 2)),
// 	   Boolean_toString(Circuit_getOutput(circuit, 0)));
// }

void testCircuit(Circuit c, int col){

    if(col == Circuit_numInputs(c) - 1){
        Circuit_setInput(c, col, false);
        Circuit_update(c);
        for(int i = 0; i < Circuit_numInputs(c); i++)
            printf("%s", Boolean_toString(Circuit_getInput(c,i )));
        printf("->");
        for(int i = 0; i < Circuit_numOutputs(c); i++)
            printf("%s", Boolean_toString(Circuit_getOutput(c, i)));
        printf("    ");

        Circuit_setInput(c, col, true);
        Circuit_update(c);
        for(int i = 0; i < Circuit_numInputs(c); i++)
            printf("%s", Boolean_toString(Circuit_getInput(c,i )));
        printf("->");
        for(int i = 0; i < Circuit_numOutputs(c); i++)
            printf("%s", Boolean_toString(Circuit_getOutput(c, i)));
        printf("    ");
        return;
    }
    Circuit_setInput(c, col, false);
    testCircuit(c, col + 1);
    Circuit_setInput(c, col, true);
    testCircuit(c, col + 1);
}

int main(int argc, char **argv) {
    printf("\n");
    printf("Circuit A: two inverters and one AND gate with 2 inputs and 1 output\n");
    Circuit circuitA = circuit_a();
    testCircuit(circuitA, 0);
    printf("\n");

    printf("Circuit B: three NAND gates with 2 inputs and 1 output\n");
    Circuit circuitB = circuit_b();
    testCircuit(circuitB, 0);
    printf("\n");

    printf("Circuit C: two AND gates, two OR gates, and 1 inverter with 3 inputs and 1 output\n");
    Circuit circuitC = circuit_c();
    testCircuit(circuitC, 0);
    printf("\n");
    printf("\n");
    printf("EXTRA CREDIT\n");
    printf("Circuit F\n");
    Circuit circuitF = circuit_f();
    testCircuit(circuitF, 0);
    printf("\n");

    printf("Circuit G\n");
    Circuit circuitG = circuit_g();
    testCircuit(circuitG, 0);
    printf("\n");
}

