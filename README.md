# Anti-Lock Braking System (ABS) using MATLAB/Simulink

## Project Overview
This project focuses on the modelling, simulation, and validation of an Anti-Lock Braking System (ABS) using MATLAB/Simulink and Model-Based Design (MBD) techniques.

The primary objective of the system is to prevent wheel lock-up during sudden braking and maintain optimal wheel slip for improved vehicle stability, steering control, and reduced stopping distance.

The ABS controller dynamically regulates brake pressure using a PID controller based on real-time wheel slip feedback.

---

## Features
- Real-time wheel slip calculation
- PID-based brake pressure control
- Vehicle and wheel dynamics modelling
- Friction coefficient estimation
- Stopping distance calculation
- MATLAB/Simulink based simulation
- SIL (Software-in-the-Loop) validation
- PIL (Processor-in-the-Loop) testing
- Auto-generated embedded C code using Embedded Coder
- GUI developed using MATLAB App Designer

---

## Technologies Used
- MATLAB
- Simulink
- Embedded Coder
- Simulink Coder
- MATLAB App Designer
- Control System Toolbox

---

## Mathematical Modelling

### 1. Vehicle Dynamics
The vehicle deceleration equation is:

\[
\frac{dV}{dt} = -\mu g
\]

Where:
- \(V\) = Vehicle velocity
- \(\mu\) = Tyre-road friction coefficient
- \(g\) = Acceleration due to gravity

---

### 2. Wheel Dynamics

\[
J_w \frac{d\omega}{dt} = \mu m_t g R_w - T_b
\]

Where:
- \(\omega\) = Wheel angular velocity
- \(m_t\) = Quarter vehicle mass
- \(R_w\) = Wheel radius
- \(T_b\) = Brake torque
- \(J_w\) = Wheel inertia

---

### 3. Wheel Slip Ratio

\[
S = \frac{V - \omega R}{V}
\]

Where:
- \(S\) = Wheel slip ratio
- \(V\) = Vehicle speed
- \(\omega\) = Wheel angular speed
- \(R\) = Wheel radius

Optimal slip value ≈ **0.2**

---

### 4. PID Control Logic

\[
u(t)=K_p e(t)+K_i \int e(t)dt + K_d \frac{de(t)}{dt}
\]

PID Gains Used:
- **Kp = 30.009**
- **Ki = 0.0002**
- **Kd = 0.191**

---

## Simulation Architecture
The ABS model contains:
- Vehicle Dynamics Subsystem
- Wheel Dynamics Subsystem
- Slip Ratio Estimator
- PID Controller
- Hydraulic Brake Pressure Block
- Friction Coefficient Estimator
- Stopping Distance Calculator

The PID controller continuously compares actual slip with desired slip and modulates brake pressure to avoid wheel lock-up.

---

## Simulation Results

### Without ABS
- Wheel lock-up occurs
- Higher stopping distance
- Loss of steering control
- Excessive slip

### With ABS
- Controlled braking
- Stable wheel slip near 0.2
- Reduced stopping distance
- Improved traction and steering stability

---

## Testing Results

| Slip Ratio | Stopping Distance | Stopping Time |
|------------|------------------|---------------|
| 0.2 | Minimum | Best Performance |
| 0.4 | Increased | Moderate |
| 0.6 | High | Poor |
| 0.8 | Very High | Worst |

Conclusion:
The stopping distance is minimum when wheel slip is maintained around **0.2**.

---

## SIL/PIL Validation
Software-in-the-Loop (SIL) and Processor-in-the-Loop (PIL) testing were performed to validate the generated embedded C code against the Simulink model.

Results showed:
- Exact matching between simulation and generated code
- No tolerance violations
- Accurate real-time execution

---

## Auto Code Generation
Embedded C code was automatically generated using:
- Simulink Coder
- Embedded Coder

Generated code includes:
- PID controller implementation
- Solver configuration
- Continuous state update logic
- Embedded compatible structure

---

## GUI
A MATLAB App Designer based GUI was developed to:
- Select vehicle type
- Automatically load vehicle parameters
- Simplify ABS performance testing

---

## Applications
- Automotive Safety Systems
- Vehicle Dynamics Research
- Embedded Automotive Control
- Model-Based Design Learning
- ABS Controller Development

---

## Future Scope
- Hardware-in-the-Loop (HIL) Testing
- Integration with Traction Control System (TCS)
- Electronic Stability Control (ESC)
- Adaptive ABS using AI/ML
- Real-time ECU deployment using STM32/Raspberry Pi

---

## Team Members
- Tejas Nandanikar
- Mahadev Lohare
- Disha Parolsande

Department of Electrical Engineering  
COEP Technological University, Pune

---

## References
1. S. John, “Artificial intelligent-based feedforward optimized PID wheel slip controller,” IEEE AFRICON, 2013.
2. Mohammed Wafi, “Modelling and Simulation of ABS through Different Types of Controllers Using Simulink.”
3. KPIT Genesis ABS Model Based Design Documentation.
