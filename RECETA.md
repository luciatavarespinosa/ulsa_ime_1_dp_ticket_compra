# Receta: Ticket de compra

## Receta del programa principal (`main`)

```text
1. Mostrar mensaje de bienvenida

2. Pedir al usuario el nombre del producto

3. Leer nombre

4. Pedir al usuario el precio unitario

5. Leer precio

6. MIENTRAS precio <= 0 HACER
      Mostrar mensaje de error
      Pedir al usuario el precio unitario
      Leer precio
   FIN MIENTRAS

7. Pedir al usuario la cantidad de piezas

8. Leer cantidad

9. MIENTRAS cantidad <= 0 HACER
      Mostrar mensaje de error
      Pedir al usuario la cantidad de piezas
      Leer cantidad
   FIN MIENTRAS

10. Pedir al usuario el porcentaje de descuento (de 0 a 99)

11. Leer descuento

12. MIENTRAS descuento < 0 o descuento > 99 HACER
       Mostrar mensaje de error
       Pedir al usuario el porcentaje de descuento
       Leer descuento
    FIN MIENTRAS

13. Calcular subtotal con calcularSubtotal(precio, cantidad)

14. Calcular montoDescuento con calcularDescuento(subtotal, descuento)

15. Calcular baseImponible restando montoDescuento al subtotal

16. Calcular iva con calcularIVA(baseImponible, TASA_IVA)

17. Calcular total sumando baseImponible y iva

18. Llamar a imprimirTicket(nombre, cantidad, precio, subtotal, montoDescuento, iva, total)
```

## Recetas de los módulos

### `calcularIVA`

```text
MODULO calcularIVA(base, tasa)

1. Recibir base y tasa

2. Calcular iva con calcularPorcentaje(base, tasa)

3. Mostrar iva y variable iva (devolver iva)

FIN MODULO
```

### `imprimirTicket`

```text
MODULO imprimirTicket(nombre, cantidad, precio, subtotal, descuentoMonto, iva, total)

1. Recibir nombre, cantidad, precio, subtotal, descuentoMonto, iva y total

2. Mostrar el título del ticket

3. Mostrar el nombre del producto

4. Mostrar el precio unitario

5. Mostrar la cantidad

6. Mostrar el subtotal

7. Mostrar el descuento

8. Mostrar el IVA

9. Mostrar una línea separadora

10. Mostrar el total

11. Mostrar mensaje de agradecimiento

FIN MODULO
```

### `calcularPorcentaje` (Fase 4)

```text
MODULO calcularPorcentaje(monto, porcentaje)

1. Recibir monto y porcentaje

2. Calcular resultado multiplicando monto por porcentaje y dividiendo entre 100.0

3. Mostrar resultado y variable resultado (devolver resultado)

FIN MODULO
```

### Otros módulos que agregues (por ejemplo, para tu reto)

```text
MODULO calcularSubtotal(precio, cantidad)

1. Recibir precio y cantidad

2. Calcular subtotal multiplicando precio por cantidad

3. Mostrar subtotal y variable subtotal (devolver subtotal)

FIN MODULO


MODULO calcularDescuento(subtotal, porcentaje)

1. Recibir subtotal y porcentaje

2. Calcular montoDescuento con calcularPorcentaje(subtotal, porcentaje)

3. Mostrar montoDescuento y variable montoDescuento (devolver montoDescuento)

FIN MODULO
```