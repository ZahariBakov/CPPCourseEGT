﻿- коли
  - движи се по пътя направо
  - решение с каква скорост да се движи
    - лимити на пътя
  - ще казва до къде е стигнала на всяка стъпка
  - различна логика за избиране на скорост:
    - бмв кола: 2 пъти по максималната скорост
    - //шофьор джип: независимо от дупките кара с макс скорост
- пътища
  - скорост (макс, мин)
  - различна скорост на различни сегменти от пътя
  - дължина (в метри)
  - дупки по пътя
    - шанс да се счупи колата (скорост на колата + пътя)
- външен таймер
- контролер
  - създава коли
  - създава пътища
  - "пуска" колата по даден път (ако няма път в момента)
- factory for road creation
  - randomized
  - from terminal
- factory for car creation
- save/load controllre to/from disk

------------------------------------------------------------------------------------

(at least) 1 virtual function => virtual destructor (very likely)
at least 1 pure virtual (= 0) function => abstract class => can't be created