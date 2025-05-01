# CubeRotator.c 🎲✨

**CubeRotator.c** is a terminal-based 3D cube rotator implemented in C. This project demonstrates the use of trigonometry and ASCII art to simulate the rotation of a cube in the terminal. It's a great example of mathematical concepts combined with simple yet visually striking code!

---

## 🚨 **Important Notice**:
Before running the project, please note:
- This project is designed to run on **Linux** or **WSL Ubuntu** (Windows Subsystem for Linux).
- If you're using **Windows** with **PowerShell**, some formatting issues may occur. To ensure compatibility, it is highly recommended to use **WSL Ubuntu** or a native Linux environment.

---

## 🔧 **Requirements**:
- **Linux** or **WSL Ubuntu** (for Windows users).
- **GCC Compiler** (GNU Compiler Collection).
- Basic knowledge of terminal commands.

---

## 📝 **Features**:
- **3D Cube Rotation**: Real-time rendering of a rotating cube using ASCII characters.
- **Math Libraries**: Uses trigonometric functions (`sin`, `cos`) from the math library for rotation.
- **Terminal Display**: Outputs the 3D animation directly into your terminal window.

---

## 🚀 **How to Run**:

### 1. **Clone the repository**:
Start by cloning the repository to your local machine:

    git clone https://github.com/Kyle-gi/CubeRotator.git

2. Navigate to the project directory:

Once the repository is cloned, navigate to the project folder:

    cd CubeRotator

3. Compile the code:

Compile the C code using gcc. Ensure you link the math library (libm) to enable the sin and cos functions.

    gcc CubeRotator.c -o CubeRotator -lm

4. Run the program:

Now that the code is compiled, run the program using:

    ./CubeRotator

You should see a rotating ASCII cube in your terminal.
⚠️ Troubleshooting:

If you run into errors like undefined references to sin or cos, make sure that:

    You are compiling with the -lm flag to link the math library.

    Ensure you are on a Linux or WSL environment. On PowerShell or other non-Linux terminals, the formatting may not work correctly.

./CubeRotator

You should see a rotating ASCII cube in your terminal.
