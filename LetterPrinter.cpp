/*!
 * \file LetterPrinter.cpp
 * \author BOUAMOUD MOHAMED-REDA, SAHNOUN MEHDI
 * \brief Implements the LetterPrinter class and its functionalities.
 */

#include "LetterPrinter.h"



/**
 * @brief Prints the letter 'A' on the PixelGrid.
 * @param table PixelGrid object to be modified.
 */
void LetterPrinter::printLetterA(PixelGrid &table)
{
    // Define control points for Bezier curves
    Curve A1(3);
    Curve A2(3);
    Curve A3(2);

    // Left diagonal
    A1[0] = Point(0.2, 0.8);
    A1[1] = Point(0.35, 0.5);
    A1[2] = Point(0.5, 0.2);

    // Right diagonal
    A2[0] = Point(0.8, 0.8);
    A2[1] = Point(0.65, 0.5);
    A2[2] = Point(0.5, 0.2);

    // Crossbar
    A3[0] = Point(0.35, 0.5);
    A3[1] = Point(0.65, 0.5);

    // Print the letter A
    LetterSelector::printLetter(table, A1, A2, A3);
}

void LetterPrinter::printLetterB(PixelGrid &table)
{
    Curve B1(2);
    Curve B2(3);
    Curve B3(3);

    B1[0] = Point(0.2, 0.2);
    B1[1] = Point(0.2, 0.8);
    B2[0] = B1[1];
    B2[1] = Point(0.7, 0.7);
    B2[2] = Point(0.2, 0.5);
    B3[0] = Point(0.2, 0.5);
    B3[1] = Point(0.7, 0.3);
    B3[2] = Point(0.2, 0.2);
    LetterSelector::printLetter(table, B1, B2, B3);

}

void LetterPrinter::printLetterC(PixelGrid &table)
{
    Curve C1(3);
    C1[0] = Point(0.7, 0.8);
    C1[1] = Point(0.3, 0.9);
    C1[2] = Point(0.2, 0.5);
    Curve C2(3);
    C2[0] = C1[2];
    C2[1] = Point(0.3, 0.1); 
    C2[2] = Point(0.7, 0.2);  
    LetterSelector::printLetter(table, C1, C2);
}

void LetterPrinter::printLetterD(PixelGrid &table)
{
    Curve D1(2);
    D1[0] = Point(0.1, 0.1);
    D1[1] = Point(0.1, 0.8);

    Curve D2(3);
    D2[0] = Point(0.1, 0.8);
    D2[1] = Point(0.4, 1.0);
    D2[2] = Point(0.6, 0.8);

    Curve D3(3);
    D3[0] = Point(0.6, 0.8);
    D3[1] = Point(0.7, 0.5);
    D3[2] = Point(0.6, 0.2);

    Curve D4(2);
    D4[0] = Point(0.6, 0.2);
    D4[1] = Point(0.1, 0.1);  

    LetterSelector::printLetter(table, D1, D2, D3, D4);
}

void LetterPrinter::printLetterE(PixelGrid &table)
{
    Curve E1(2);
    E1[0] = Point(0.1, 0.2);
    E1[1] = Point(0.1, 0.8);

    Curve E2(2);
    E2[0] = Point(0.1, 0.8);
    E2[1] = Point(0.6, 0.8);

    Curve E3(2);
    E3[0] = Point(0.1, 0.5);
    E3[1] = Point(0.6, 0.5);

    Curve E4(2);
    E4[0] = Point(0.1, 0.2);
    E4[1] = Point(0.6, 0.2);

    LetterSelector::printLetter(table, E1, E2, E3, E4);
}
void LetterPrinter::printLetterF(PixelGrid &table)
{
    Curve F1(2);
    F1[0] = Point(0.1, 0.2);
    F1[1] = Point(0.1, 0.8);

    Curve F2(2);
    F2[0] = Point(0.1, 0.5);
    F2[1] = Point(0.6, 0.5);

    Curve F3(2);
    F3[0] = Point(0.1, 0.2);
    F3[1] = Point(0.6, 0.2);

    LetterSelector::printLetter(table, F1, F2, F3);
}

void LetterPrinter::printLetterG(PixelGrid &table)
{
    Curve G1(3);
    Curve G2(3);
    Curve G3(2);
    Curve G4(2);

    G1[0] = Point(0.7, 0.8);  
    G1[1] = Point(0.3, 0.9);  
    G1[2] = Point(0.2, 0.5);  

    G2[0] = G1[2];            
    G2[1] = Point(0.3, 0.1);  
    G2[2] = Point(0.7, 0.2); 

    G3[0] = Point(0.7, 0.8);
    G3[1] = Point(0.7, 0.5);

    G4[0] = Point(0.7, 0.5);
    G4[1] = Point(0.55, 0.5);

    LetterSelector::printLetter(table, G1, G2, G3, G4);
}

void LetterPrinter::printLetterH(PixelGrid &table)
{
    Curve H1(2);
    Curve H2(2);
    Curve H3(2);
    H1[0] = Point(0.2, 0.8);
    H1[1] = Point(0.2, 0.2);
    H2[0] = Point(0.2, 0.5);
    H2[1] = Point(0.6, 0.5);
    H3[0] = Point(0.6, 0.8);
    H3[1] = Point(0.6, 0.2);

    LetterSelector::printLetter(table, H1, H2, H3);
}
void LetterPrinter::printLetterI(PixelGrid &table)
{
    Curve I1(2);
    Curve I2(2);
    Curve I3(2);
    I1[0] = Point(0.2, 0.88);
    I1[1] = Point(0.4, 0.88);
    I2[0] = Point(0.2, 0.2);
    I2[1] = Point(0.4, 0.2);
    I3[0] = Point(0.3, 0.2);
    I3[1] = Point(0.3, 0.88);

    LetterSelector::printLetter(table, I1, I2, I3);
}
void LetterPrinter::printLetterJ(PixelGrid &table)
{
    Curve J1(2);
    Curve J2(2);
    Curve J3(3);
    J1[0] = Point(0.2, 0.2);
    J1[1] = Point(0.5, 0.2);
    J2[0] = J1[1];
    J2[1] = Point(0.5, 0.5);
    J3[0] = J2[1];
    J3[1] = Point(0.6, 0.9);
    J3[2] = Point(0.2, 0.8);
    LetterSelector::printLetter(table, J1, J2, J3);
}
void LetterPrinter::printLetterK(PixelGrid &table)
{
    Curve K1(2);
    Curve K2(2);
    Curve K3(2);
    K1[0] = Point(0.2, 0.2);
    K1[1] = Point(0.2, 0.8);
    K2[0] = Point(0.2, 0.5);
    K2[1] = Point(0.6, 0.2);
    K3[0] = K2[0];
    K3[1] = Point(0.6, 0.8);

    LetterSelector::printLetter(table, K1, K2, K3);
}
void LetterPrinter::printLetterL(PixelGrid &table)
{
    Curve L1(2);
    Curve L2(2);
    L1[0] = Point(0.2, 0.2);
    L1[1] = Point(0.2, 0.8);
    L2[0] = L1[1];
    L2[1] = Point(0.7, 0.8);

    LetterSelector::printLetter(table, L1, L2);
}
void LetterPrinter::printLetterM(PixelGrid &table)
{
    Curve M1(2);
    Curve M2(2);
    Curve M3(2);
    Curve M4(2);
    M1[0] = Point(0.2, 0.2);
    M1[1] = Point(0.2, 0.8);
    M2[0] = M1[0];
    M2[1] = Point(0.5, 0.5);
    M3[0] = M2[1];
    M3[1] = Point(0.8, 0.2);
    M4[0] = M3[1];
    M4[1] = Point(0.8, 0.8);

    LetterSelector::printLetter(table, M1, M2, M3, M4);
}
void LetterPrinter::printLetterN(PixelGrid &table)
{
    Curve N1(2);
    Curve N2(2);
    Curve N3(2);
    N1[0] = Point(0.2, 0.8);
    N1[1] = Point(0.2, 0.2);
    N2[0] = N1[1];
    N2[1] = Point(0.7, 0.8);
    N3[0] = N2[1];
    N3[1] = Point(0.7, 0.2);

    LetterSelector::printLetter(table, N1, N2, N3);
}
void LetterPrinter::printLetterO(PixelGrid &table)
{
    Curve O1(3);
    Curve O2(3);
    Curve O3(3);
    Curve O4(3);
    O1[0] = Point(0.3, 0.5);
    O1[1] = Point(0.3, 0.9);
    O1[2] = Point(0.6, 0.9);
    O2[0] = O1[2];
    O2[1] = Point(0.9, 0.9);
    O2[2] = Point(0.9, 0.5);
    O3[0] = O2[2];
    O3[1] = Point(0.9, 0.1);
    O3[2] = Point(0.6, 0.1);
    O4[0] = O3[2];
    O4[1] = Point(0.3, 0.1);
    O4[2] = O1[0];

    LetterSelector::printLetter(table, O1, O2, O3, O4);
}
void LetterPrinter::printLetterP(PixelGrid &table)
{
    Curve P1(2);
    Curve P2(3);
    P1[0] = Point(0.2, 0.1);
    P1[1] = Point(0.2, 0.9);
    P2[0] = P1[0];
    P2[1] = Point(1.0, 0.3);
    P2[2] = Point(0.2, 0.5);

    LetterSelector::printLetter(table, P1, P2);
}
void LetterPrinter::printLetterQ(PixelGrid &table)
{
    int size = std::max(table.get_width(), table.get_height());
    CurveDataset T(size);
    Curve Q1(3);
    Curve Q2(3);
    Curve Q3(3);
    Curve Q4(3);
    Curve Q5(2);

    Q1[0] = Point(0.3, 0.5);
    Q1[1] = Point(0.3, 0.9);
    Q1[2] = Point(0.6, 0.9);
    Q2[0] = Q1[2];
    Q2[1] = Point(0.9, 0.9);
    Q2[2] = Point(0.9, 0.5);
    Q3[0] = Q2[2];
    Q3[1] = Point(0.9, 0.1);
    Q3[2] = Point(0.6, 0.1);
    Q4[0] = Q3[2];
    Q4[1] = Point(0.3, 0.1);
    Q4[2] = Q1[0];
    Q5[0] = Point(0.7, 0.7);
    Q5[1] = Point(0.9, 0.9);

    LetterSelector::printLetter(table, Q1, Q2, Q3, Q4, Q5);
}
void LetterPrinter::printLetterR(PixelGrid &table)
{
    Curve R1(2);
    Curve R2(2);
    Curve R3(3);
    R1[0] = Point(0.2, 0.1);
    R1[1] = Point(0.2, 0.9);
    R3[0] = R1[0];
    R3[1] = Point(1.0, 0.3);
    R3[2] = Point(0.2, 0.5);
    R2[0] = Point(0.2, 0.4);
    R2[1] = Point(0.7, 0.9);

    LetterSelector::printLetter(table, R1, R2, R3);
}
void LetterPrinter::printLetterS(PixelGrid &table)
{
    Curve S1(2);
    Curve S2(3);
    Curve S3(2);
    Curve S4(3);
    Curve S5(2);

    S1[0] = Point(0.3, 0.8);
    S1[1] = Point(0.5, 0.8);

    S2[0] = S1[1];
    S2[1] = Point(0.9, 0.95);
    S2[2] = Point(0.6, 0.6);

    S3[0] = S2[2];
    S3[1] = Point(0.3, 0.6);

    S4[0] = S3[1];
    S4[1] = Point(0.0, 0.3);
    S4[2] = Point(0.4, 0.4);

    S5[0] = S4[2];
    S5[1] = Point(0.6, 0.4);

    LetterSelector::printLetter(table, S1, S2, S3, S4, S5);
}


void LetterPrinter::printLetterT(PixelGrid &table)
{
    Curve T1(2);
    Curve T2(2);
    T1[0] = Point(0.2, 0.1);
    T1[1] = Point(0.8, 0.1);
    T2[0] = Point(0.5, 0.1);
    T2[1] = Point(0.5, 0.9);
    LetterSelector::printLetter(table, T1, T2);
}

void LetterPrinter::printLetterU(PixelGrid &table)
{
    Curve U1(3);
    Curve U2(2);
    Curve U3(2);
    
    U1[0] = Point(0.3, 0.55);
    U1[1] = Point(0.55, 0.8);
    U1[2] = Point(0.8, 0.55);
    
    U2[0] = Point(0.3, 0.55);
    U2[1] = Point(0.3, 0.1);
    
    U3[0] = Point(0.8, 0.55);
    U3[1] = Point(0.8, 0.1);

    LetterSelector::printLetter(table, U1, U2, U3);
}

void LetterPrinter::printLetterV(PixelGrid &table)
{
    Curve V1(2);
    Curve V2(2);
    V1[0] = Point(0.3, 0.2);
    V1[1] = Point(0.55, 0.8);
    V2[0] = Point(0.8, 0.2);
    V2[1] = Point(0.55, 0.8);

    LetterSelector::printLetter(table, V1, V2);
}
void LetterPrinter::printLetterW(PixelGrid &table)
{
    Curve W1(2);
    Curve W2(2);
    Curve W3(2);
    Curve W4(2);
    W1[0] = Point(0.1, 0.2);
    W1[1] = Point(0.3, 0.9);
    W2[0] = W1[1];
    W2[1] = Point(0.5, 0.5);
    W3[0] = W2[1];
    W3[1] = Point(0.7, 0.9);
    W4[0] = W3[1];
    W4[1] = Point(0.9, 0.2);

    LetterSelector::printLetter(table, W1, W2, W3, W4);
}
void LetterPrinter::printLetterX(PixelGrid &table)
{
    Curve X1(2);
    Curve X2(2);
    X1[0] = Point(0.2, 0.3);
    X1[1] = Point(0.8, 0.9);
    X2[0] = Point(0.8, 0.3);
    X2[1] = Point(0.2, 0.9);

    LetterSelector::printLetter(table, X1, X2);
}
void LetterPrinter::printLetterY(PixelGrid &table)
{
    Curve Y1(2);
    Curve Y2(2);
    Curve Y3(2);
    Y1[0] = Point(0.6, 0.9);
    Y1[1] = Point(0.6, 0.6);
    Y2[0] = Y1[1];
    Y2[1] = Point(0.4, 0.2);
    Y3[0] = Y1[1];
    Y3[1] = Point(0.8, 0.2);
    LetterSelector::printLetter(table, Y1, Y2, Y3);
}
void LetterPrinter::printLetterZ(PixelGrid &table)
{
    Curve Z1(2);
    Curve Z2(2);
    Curve Z3(2);
    Z1[0] = Point(0.8, 0.2);
    Z1[1] = Point(0.3, 0.2);
    Z2[0] = Z1[0];
    Z2[1] = Point(0.3, 0.8);
    Z3[0] = Z2[1];
    Z3[1] = Point(0.8, 0.8);
    LetterSelector::printLetter(table, Z1, Z2, Z3);
}
