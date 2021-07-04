from math import pi
import numpy as np
import matplotlib.pyplot as plt
from math import *
import time
from scipy.integrate import ode

ts = []
ys = []
gamm = []
Is = []
normTs = []

def fout(t, y):  # обработчик шага
   ts.append(t)
   ys.append(list(y.copy()))
# функция правых частей системы ОДУ
def f(t, y, k):  # имеется дополнительный аргумент k
# емкость конденсаторов
   C_1 = 5e-6
   C_2 = 5e-6
   C_3 = 4e-6
   # Обратное число емкости конденсатора
   # индуктивность катушек
   L = 10
   # сопротивление резисторов
   R_1 = 9
   R_2 = 9
   R_3 = 9
   # напряжение источников тока
   U = 10

   I_1, I_2, I_3, Q_1, Q_2, Q_3 = y
   newI_1 = (U - Q_1/C_1 - Q_3/(C_2 * R_2) - Q_3/(C_3 * R_2) + Q_2 / (C_3 * R_2)) / (R_1 + R_2 + R_3 - 1)
   newI_3 = -Q_3 / (C_2 * R_2) + newI_1 - Q_3 / (C_3 * R_2) + Q_2 / (C_3 * R_2)
   newI_2 = Q_3 / (L * C_3) - Q_2 / (L * C_3)
   if (t < 1):
      Is.append([newI_1-newI_1*t, newI_2, newI_3-newI_3*t, Q_1, Q_2, Q_3])
   else:
      Is.append([0, newI_2, 0, Q_1, Q_2, Q_3])
   normTs.append(t)
   return [newI_1, newI_2, newI_3, I_1, I_2, I_3]
   '''
   newI1 = (U + I3 * R_3 - I1 * R_1 - I1 * R_3 - Q1/C_1) / L_1
   newI2 = (-Q2 / C_3 - Q2 / C_4 + U) / L_3
   newI3 = (-Q3/ C_2 - I3 * R_4 - I3 * R_2 - I3 * R_2 + I1 * R_3) / L_1
   Is.append([I1, I2, I3, Q1, Q2, Q3])
   normTs.append(t)
   return [newI1, newI2, newI3, I1, I2, I3]
   '''
   '''
   S_1 = U / R_1 - Q_1 / (C_2 * R_1) + Q_2 / (C_2 * R_1) + (S_2 + S_3) * R_2 / R_1
   newS_2 = (R_2 * S_1 - R_2 * (S_2 + S_3)) / L_2
   newS_3 = (R_2 * S_1 - R_2 * (S_2 + S_3) / R_1 + Q_1 / C_2 - Q_3 / C_2 - S_3 * R_3 - Q_3 / C_3 - Q_3 / C_4 - S_3 * R_1 - Q_3 / C_1) / L_1
   Is.append([S_1, S_2 + S_3, S_3, Q_1, Q_2, Q_3])
   normTs.append(t)
   return [newS_2, newS_3, S_1, S_2 + S_3, S_3]
   '''

tmax = 100  # максимально допустимый момент времени
I10 = 0
I20 = 0
I30 = 0
Q10 = 10e-6
Q20 = 10e-6
Q30 = 10e-6
y0, t0 = [I10, I20 , I30, Q10, Q20, Q30], 0  # начальные условия
ODE = ode(f)
ODE.set_integrator("dopri5" ,max_step = 0.0001, nsteps = 10000)
ODE.set_solout(fout)
fig, ax = plt.subplots()
fig.set_facecolor('white')
ODE.set_initial_value(y0, t0)  # задание начальных значений
ODE.set_f_params(0)  # передача дополнительного аргумента k     # в функцию f(t,y,k) правых частей системы ОДУ
ODE.integrate(tmax)  # решение ОДУ
T = np.array(normTs)
Y = np.array(Is)
plt.plot(T[:], Y[:, 0], linewidth=3, label='I1')
plt.plot(T[:], Y[:, 1], linewidth=3, label='I2')
plt.plot(T[:], Y[:, 2], linewidth=3, label='I3')
stop = time.time()
plt.grid(True)
# plt.xlim(0,8)
# plt.ylim(-0.1,2)
plt.legend(loc='best')
plt.show()
