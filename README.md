# Modelling and Simulation of Anti-Lock Braking System (ABS) using MATLAB/Simulink

## Project overview
This project models and simulates an **Anti-Lock Braking System (ABS)** using **MATLAB/Simulink** with **Model-Based Design (MBD)** practices. The ABS controller prevents wheel lock-up during sudden braking by regulating brake pressure to keep the **wheel slip ratio** near an optimal value (typically **~0.2**) for improved traction, stability, and steering control.

## Key highlights
- **Closed-loop slip control** using a **PID controller** to modulate brake pressure/torque.
- **Vehicle + wheel dynamics** modelling, including tyre-road friction characteristics.
- **Performance comparison**: braking behaviour **with ABS** vs **without ABS**.
- **Verification/Validation** using **SIL** and **PIL** style testing to compare simulation vs generated-code behaviour.
- **GUI** built using **MATLAB App Designer** to load vehicle parameters via a dropdown (auto-populated into MATLAB base workspace).

## Objectives
- Design and simulate an ABS using MATLAB/Simulink
- Calculate and monitor wheel slip ratio in real time
- Prevent wheel lock-up during sudden braking
- Maintain slip within an optimum range for maximum traction
- Implement a PID-based brake pressure controller
- Estimate tyre-road friction coefficient under varying conditions
- Analyse stopping distance for different slip ratios
- Validate generated embedded code using SIL/PIL testing
- Understand real-world automotive safety systems using Model-Based Design techniques

## Mathematical model (core equations)
### Vehicle longitudinal dynamics
\[
\frac{dV}{dt} = -\mu g
\]
Where:
- \(V\): vehicle speed  
- \(\mu\): tyre-road friction coefficient  
- \(g\): gravitational acceleration

### Wheel rotational dynamics
\[
\frac{d\omega}{dt} = \frac{\mu m_t g R_w - T_b}{J_w}
\]
Where:
- \(\omega\): wheel angular speed  
- \(m_t\): quarter-vehicle mass  
- \(R_w\): wheel radius  
- \(T_b\): braking torque  
- \(J_w\): wheel moment of inertia

### Wheel slip ratio
\[
S = \frac{V - \omega R}{V}
\]
Where:
- \(S\): slip ratio  
- \(R\): wheel radius  

The controller aims to keep \(S\) close to **~0.2** to achieve high traction while avoiding lock-up.

## Control strategy (PID)
The PID controller compares desired slip ratio vs actual slip ratio and outputs a brake actuation command:
\[
u(t) = K_p e(t) + K_i \int e(t)\,dt + K_d \frac{de(t)}{dt}
\]
Where:
- \(e(t)\): slip error  
- \(K_p, K_i, K_d\): PID gains

**Gains used**
- \(K_p = 30.009\)
- \(K_i = 0.0002\)
- \(K_d = 0.191\)

## Model architecture (Simulink)
The model is built with modular subsystems (vehicle dynamics, wheel dynamics, slip calculation, brake pressure control, stopping distance estimation, etc.). Signals flow from vehicle/wheel states → slip calculation → PID controller → brake modulation.

![Simulink model / simulation image](Simulation%20Image.png)

## Results (with ABS vs without ABS)
Without ABS, wheel lock-up occurs quickly under hard braking, causing excessive slip, unstable deceleration, increased stopping distance, and reduced steering control.  
With ABS, brake pressure is modulated to maintain slip near ~0.2, improving stability and reducing stopping distance.

![Simulation result without ABS](Simulation%20Result%20Without%20ABS.png)

![Simulation result with ABS](Simulation%20Result%20With%20ABS.png)

## Testing and observations (slip sweep)
Testing at multiple slip targets shows stopping distance is **minimum around slip = 0.2**, supporting ~0.2 as an optimal slip value for the chosen friction model and conditions.

![Testing results for slip 0.2](Testing%20Reults%20for%200.2%20slip.png)
![Testing results for slip 0.4](Testing%20Reults%20for%200.4%20slip.png)
![Testing results for slip 0.6](Testing%20Reults%20for%200.6%20slip.png)
![Testing results for slip 0.8](Testing%20Reults%20for%200.8%20slip.png)

## Vehicle parameters
Vehicle datasets used for testing are summarized here:

![Vehicle parameters](Vehicle%20Parameters%20Used.png)

## GUI (MATLAB App Designer)
The GUI allows selecting a vehicle from a dropdown; selected vehicle parameters are loaded automatically into the MATLAB base workspace to run the ABS performance checks.

![GUI](GUI%20Interface%20Image.png)

## SIL testing results (model vs generated code)
SIL results indicate simulation and generated-code outputs match closely.

![SIL testing results 1](SIl%20Testing%20Results%201.png)
![SIL testing results 2](SIl%20Testing%20Results%202.png)
![SIL testing results 3](SIl%20Testing%20Results%203.png)

## Repository contents
- `README.md`: this document
- `KPIT Project.docx`: original project document
- `KPIT Project.extracted.txt`: extracted text (used to build the README)
- `KPIT Internship Report.pdf`: internship report
- `final operation video.mp4`: demo/operation video
- `*.png`: figures used throughout the documentation

## References
1. S. John, “Artificial intelligent-based feedforward optimized PID wheel slip controller,” Proc. IEEE AFRICON Conf., 2013.
2. Mohammed Wafi, “Modelling and Simulation of ABS through Different Types of Controllers Using Simulink.”

