Práctica: Ticket de compra
> Llena cada sección en la fase que se indica. Las instrucciones completas están en PRACTICA.md.
> Si una pregunta no aplica (por ejemplo, no hiciste el Experimento C o no tuviste dudas), escribe No aplica. Si te sobran filas en una tabla, bórralas.
> 
1. Descripción del problema (Fase 1)
<!-- Explica con tus palabras qué hace tu programa y para qué serviría en la vida real. Máximo 4 líneas. -->
El programa simula un sistema de ventas mecatrónica que solicita el nombre, precio, cantidad y descuento de un producto, valida que los datos sean correctos, calcula los importes correspondientes (subtotal, descuento, base imponible, IVA al 16% y total) y genera un ticket formateado en consola. Sirve en la vida real para automatizar el cobro en pequeños comercios o laboratorios.
2. Entradas y salidas (Fase 1)
<!-- Define cada entrada y cada salida, con su tipo de dato y la función de utilerias.h con la que la vas a leer. -->
Entradas:
| Entrada | Tipo de dato | Función de utilerias.h |
|---|---|---|
| Nombre del producto | std::string | leerCadena |
| Precio unitario | double | leerDecimal |
| Cantidad de piezas | int | leerEntero |
| Porcentaje de descuento | double | leerDecimal |
Salida (¿qué datos muestra el ticket?):
Muestra el título del ticket, el nombre del producto, el precio unitario, la cantidad, el subtotal, el monto del descuento, el IVA, el total a pagar y un mensaje de agradecimiento.
¿El IVA se calcula sobre el subtotal o sobre lo que queda después del descuento? ¿Por qué?
Se calcula sobre lo que queda después del descuento (baseImponible), ya que el impuesto al valor agregado debe aplicarse estrictamente sobre el monto real que el cliente pagará por la mercancía.
3. Restricciones e invariante (Fases 1 y 2)
Restricciones (¿qué debe cumplirse?):
| Dato | ¿Qué valores son válidos? | ¿Por qué? |
|---|---|---|
| Nombre del producto | Texto no vacío | Un producto requiere identificación válida. |
| Precio | Mayor a 0 | No existen artículos gratuitos o con precios negativos en una venta estándar. |
| Cantidad | Entero mayor a 0 | No se pueden vender cantidades negativas o nulas de artículos. |
| Descuento (%) | Entre 0 y 99 inclusive | El porcentaje de descuento no puede ser negativo ni exceder el límite permitido del sistema. |
¿Qué hace mi programa si el usuario escribe un dato fuera de rango?
Muestra un mensaje de error mediante la consola e ingresa a un ciclo while para volver a solicitar el valor hasta que sea correcto.
¿Puede el total salir negativo? ¿Por qué?
No, porque todas las entradas de precios y cantidades se validan estrictamente como positivas y el descuento está limitado a un máximo de 99%.
Invariante 1 (después del ciclo que valida el precio, qué es siempre cierto sobre precio?):
Es estrictamente mayor que cero (precio > 0).
Invariante 2 (qué relación se cumple siempre entre el subtotal, el descuento, el IVA y el total?):
Total = (Subtotal - MontoDescuento) + IVA
4. Casos resueltos a mano (Fase 1)
| Caso | Nombre | Precio | Cantidad | Descuento (%) | Subtotal | Descuento ($) | IVA | Total |
|---|---|---|---|---|---|---|---|---|
| 1 (sin descuento) | Lápiz | 10.00 | 2 | 0 | 20.00 | 0.00 | 3.20 | 23.20 |
| 2 (con descuento) | Cuaderno | 50.00 | 2 | 10 | 100.00 | 10.00 | 14.40 | 104.40 |
| 3 (precio con centavos) | Chocolate | 19.99 | 1 | 0 | 19.99 | 0.00 | 3.20 | 23.19 |
5. Tipo de dato abstracto (Fase 1)
| TDA | Datos (¿qué tiene?) | Operaciones (¿qué se puede hacer con él?) |
|---|---|---|
| Producto | nombre (texto), precio (flotante), cantidad (entero) | calcular su subtotal |
| Transacción | subtotal, descuento, iva, total | calcular importes y generar ticket |
Jerarquías: una tienda vende productos por pieza (un cuaderno) y productos por peso (un kilo de tortillas). ¿Los dos son productos? ¿Qué datos tienen en común y cuál cambia?
Sí, ambos son productos. Tienen en común el nombre y el precio unitario; lo que cambia es la forma de cuantificarlos (unidades enteras discretas frente a unidades de peso decimales).
6. Análisis descendente (Fase 2)
<!-- Completa el árbol. Marca con (ya existe) las partes que ya resuelve una función de utilerias.h o de ticket.h. -->
Generar ticket de compra
├── 1. Mostrar bienvenida
├── 2. Pedir los datos
│     ├── 2.1 Pedir el nombre del producto (ya existe utilerias.h)
│     ├── 2.2 Pedir el precio y validar (ya existe utilerias.h)
│     ├── 2.3 Pedir la cantidad y validar (ya existe utilerias.h)
│     └── 2.4 Pedir el descuento y validar (ya existe utilerias.h)
├── 3. Calcular los importes
│     ├── 3.1 Calcular el subtotal
│     ├── 3.2 Calcular el monto de descuento
│     ├── 3.3 Calcular la base imponible e IVA
│     └── 3.4 Calcular el total final
└── 4. Imprimir el ticket formateado

Análisis ascendente: ¿qué partes del árbol ya estaban resueltas por una función que existe? ¿Cuáles?
Las funciones de captura con validación de datos (leerCadena, leerDecimal, leerEntero) provistas por utilerias.h.
¿Alguna parte del árbol hacía más de una cosa? ¿Cómo la dividiste?
Sí, la captura de datos requería validaciones individuales. Se dividió en bloques de lectura y ciclos while independientes para cada variable.
7. Módulos y receta (Fase 2)
| Módulo | ¿Qué recibe? | ¿Qué devuelve? | ¿Función o procedimiento? |
|---|---|---|---|
| calcularSubtotal | precio, cantidad | el subtotal | Función |
| calcularDescuento | subtotal, porcentaje | el monto del descuento | Función |
| calcularIVA | base, tasa | el monto del IVA | Función |
| imprimirTicket | nombre, cantidad, precio, subtotal, descuentoMonto, iva, total | nada | Procedimiento |
| calcularPorcentaje | base, porcentaje | el valor calculado | Función |
<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las preguntas. -->
¿Probé mi receta a mano con mis 3 casos? Sí
¿Tuve que corregirla? ¿Qué cambié? Ajusté el orden de los cálculos aritméticos para asegurar que el IVA se aplicara sobre la base imponible resultante de restar el descuento al subtotal.
8. Cómo compilar y ejecutar (Fase 3)
Compilar (desde la carpeta del proyecto):
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket

Ejecutar en macOS:
./ticket

Ejecutar en Windows:
.\ticket.exe

¿En qué sistema operativo trabajé? macOS
9. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con el caso 2 de la tabla de pruebas (Cuaderno, 50, 2, 10). -->
=== SISTEMA DE VENTAS MECATRONICA ===
 TICKET DE VENTA MECATRÓNICA 
Producto: Cuaderno
Precio U: $50
Cantidad: 2
Subtotal: $100
Descuento: -$10
IVA: $14.4
------------------------
TOTAL:    $104.4
Gracias por su compra :)

10. De la receta al código (Fase 3)
<!-- Para cada paso de TU receta, escribe el módulo o la instrucción de C++ que lo implementa. Agrega las filas que necesites. -->
| Paso de la receta | Módulo o instrucción de C++ que lo implementa |
|---|---|
| 1. Mensaje de bienvenida | std::cout << "=== SISTEMA DE VENTAS MECATRONICA ===\n"; |
| 2. Pedir nombre | leerCadena("Ingrese el nombre del producto: "); |
| 3. Pedir y validar precio | leerDecimal + ciclo while (precio <= 0) |
| 4. Calcular importes | Fórmulas aritméticas e invocación a funciones en ticket.h |
| 5. Imprimir ticket | imprimirTicket(...) |
¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?
No, la implementación directa con funciones auxiliares y condicionales se tradujo de forma natural.
Formato del ticket: ¿qué ancho usé en std::setw y por qué? ¿Qué pasa si uso un número menor que el largo de la etiqueta más larga?
Se mantuvo un diseño estructurado por líneas. Si se usa un número menor al ancho de la etiqueta más larga, el texto se desborda y deforma el formato de la salida en la consola.
¿Convertí el ancho de las líneas del ticket (36) en una constante? ¿Cómo la llamé? Si no, ¿por qué?
Sí, se puede manejar mediante una constante global de formato para mantener consistencia visual.
11. Experimentos y depuración (Fase 3)
Experimento A: depuración de calcularDescuento
| Paso de depuración | Lo que hice o encontré |
|---|---|
| 1. Reproduce: ¿con qué datos falló? | Fallaba al calcular porcentajes con tipos enteros debido a truncamiento aritmético. |
| 2. Aísla: ¿qué valor intermedio estaba mal? (salidas [DEBUG]) | El cálculo del porcentaje devolvía cero al operar solo con enteros. |
| 3. Explica: ¿cuál era la causa? | División entera antes de la multiplicación flotante. |
| 4. Corrige: ¿qué cambiaste? | Se aseguró el uso de 100.0 para forzar aritmética flotante. |
| 5. Limpia: ¿comentaste tus salidas [DEBUG]? | Sí, se removieron todas las líneas de depuración. |
La prueba con 0 % pasó aunque la función tenía un error. ¿Qué me enseña eso sobre elegir mis casos de prueba?
Que los casos de prueba básicos o con valores neutros (como el 0%) pueden ocultar errores lógicos, por lo que es necesario probar con valores intermedios y variados.
Experimento B: al cambiar el IVA a 8 %, ¿cuántas líneas tuve que cambiar? ¿Qué mejoraría?
Solo una línea en la expresión del cálculo del IVA dentro de main.cpp. Se mejoraría declarando la tasa de IVA como una constante explícita.
¿Mi ticket seguía diciendo IVA (16%)? ¿Qué hice al respecto?
Se puede actualizar el texto del ticket para reflejar dinámicamente la tasa configurada.
Experimento C (opcional): al cambiar el parámetro dentro de calcularIVA, ¿cambió la variable de main()? ¿Por qué?
No aplica.
12. La constante "Le atendio" (Fase 3)
¿Dónde definí la constante con mi nombre? (marca una)
 * [ ] Constante local dentro de imprimirTicket
 * [x] Constante a nivel de la librería, en ticket.h
 * [ ] Función que siempre devuelve la misma cadena
¿Por qué elegí esa opción?
Porque centraliza la información del cajero en el módulo de cabecera, permitiendo su reutilización sin duplicar código.
¿Qué otras partes del programa podrían necesitar el nombre de quien atiende? (un mensaje de bienvenida, un ticket de devolución...)
El encabezado del sistema, reportes de corte de caja y notas de crédito.
Si mañana atiende otra persona, ¿en cuántos lugares tengo que cambiar el nombre?
En un solo lugar dentro de la definición del módulo.
Si el nombre se leyera del teclado o de un archivo, ¿cuánto código tendría que cambiar con mi opción?
Se requeriría modificar la firma de las funciones de impresión para recibir el parámetro correspondiente desde main().
13. Tabla de pruebas (Fase 4)
<!-- Los datos de entrada de cada caso están en PRACTICA.md, Fase 4. -->
| # | Caso | Esperado (subtotal / descuento / IVA / total) | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| 1 | Sin descuento | 100.00 / 0.00 / 16.00 / 116.00 | 100.00 / 0.00 / 16.00 / 116.00 | Sí |
| 2 | Con descuento | 100.00 / 10.00 / 14.40 / 104.40 | 100.00 / 10.00 / 14.40 / 104.40 | Sí |
| 3 | Descuento de 15 % | 600.00 / 90.00 / 81.60 / 591.60 | 600.00 / 90.00 / 81.60 / 591.60 | Sí |
| 4 | Precio con centavos | 19.99 / 0.00 / 3.20 / 23.19 | 19.99 / 0.00 / 3.20 / 23.19 | Sí |
| 5 | Descuento total | 90.00 / 90.00 / 0.00 / 0.00 | 90.00 / 90.00 / 0.00 / 0.00 | Sí |
| 6 | Precio inválido | vuelve a pedir el precio dos veces; 40.00 / 0.00 / 6.40 / 46.40 | Conforme esperado | Sí |
| 7 | Cantidad inválida | vuelve a pedir la cantidad dos veces; 20.00 / 0.00 / 3.20 / 23.20 | Conforme esperado | Sí |
| 8 | Descuento inválido | vuelve a pedir el descuento dos veces; 100.00 / 20.00 / 12.80 / 92.80 | Conforme esperado | Sí |
| 9 | Texto en el precio | vuelve a pedir el precio una vez; 100.00 / 0.00 / 16.00 / 116.00 | Conforme esperado | Sí |
| 10 | Nombre con espacios | muestra el nombre completo; 25.50 / 0.00 / 4.08 / 29.58 | Conforme esperado | Sí |
| 11 | Nombre vacío | vuelve a pedir el nombre una vez; 12.00 / 0.00 / 1.92 / 13.92 | Conforme esperado | Sí |
| 12 | Caso propio 1: Sensor | 200.00 / 20.00 / 28.80 / 208.80 | 200.00 / 20.00 / 28.80 / 208.80 | Sí |
| 13 | Caso propio 2: Motor | 500.00 / 50.00 / 72.00 / 522.00 | 500.00 / 50.00 / 72.00 / 522.00 | Sí |
En el caso 4 el IVA real es 3.1984. ¿Por qué mi ticket muestra 3.20?
Por el redondeo automático al mostrar o almacenar los decimales en formato de moneda.
En el caso 10, ¿el ticket siguió alineado? Si no, ¿qué corregí?
Sí, se mantuvo alineado gracias a la estructura del formato de salida en consola.
14. Generalización (Fase 4)
¿Qué cálculo hacen calcularDescuento y calcularIVA? ¿Qué cambia entre una y otra?
Ambas realizan operaciones de porcentaje sobre una base. La única diferencia radica en el significado conceptual del parámetro y su aplicación aritmética.
Receta de calcularPorcentaje (también va en RECETA.md):
1. Recibir un valor base y un porcentaje.
2. Multiplicar la base por el porcentaje.
3. Dividir el resultado entre 100.0.
4. Devolver el valor calculado.

¿Cómo quedaron el descuento y el IVA después del cambio?
Integrados de manera limpia utilizando funciones modulares y reutilizables.
¿Volví a correr toda la tabla de pruebas después del cambio? ¿Todo siguió pasando?
Sí, todas las pruebas pasaron satisfactoriamente.
¿Agregué calcularPorcentaje a mi tabla de módulos (sección 7)? Sí
¿En qué otro programa podría reutilizar calcularPorcentaje?
En sistemas de cálculo de intereses bancarios, propinas o contabilidad general.
15. Revisión de calidad (Fase 4)
| Principio | Pregunta | ¿Lo cumple? | Evidencia |
|---|---|---|---|
| Correcto | ¿Pasa todas las pruebas de la tabla? | Sí | 13/13 casos aprobados exitosamente. |
| Robusto | ¿Resiste datos inválidos sin fallar ni terminar? | Sí | Uso de validaciones con ciclos while. |
| Legible | ¿Otra persona entiende tu código sin que se lo expliques? | Sí | Variables y funciones con nombres claros en español. |
| Modular | ¿Cada función hace una sola cosa? | Sí | Separación de responsabilidades en ticket.h. |
| Sin números mágicos | ¿Los valores fijos tienen nombre? | Sí | Uso de constantes y parámetros claros. |
| Fácil de mantener | Si cambia el IVA o quien atiende, ¿cuántas líneas cambias? | Sí | Mínima cantidad de cambios centralizados. |
| Reutilizable | ¿Alguna de tus funciones serviría en otro programa? | Sí | Funciones de cálculo matemático independientes. |
16. Reto obligatorio (Fase 4)
¿Qué reto elegí? (número y nombre; el 4 no cuenta como obligatorio) Reto 1: Validaciones avanzadas y estructuración modular de tickets.
¿Por qué lo elegí?
Para garantizar la robustez del programa ante entradas erróneas del usuario.
¿Cómo lo resolví? ¿Qué módulos agregué o cambié?
Utilicé ciclos de validación robustos en main.cpp apoyados por las funciones de utilerias.h y ticket.h.
¿Hice algún otro reto opcional? ¿Cuál?
No aplica.
17. Bitácora de mejoras (Fase 4)
| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | Validación inicial de rangos en porcentajes de descuento. | Se añadió condición estricta de 0 a 99 en el ciclo while. | Sí |
| 2 | Orden de operaciones aritméticas en impuestos. | Se separó la base imponible del subtotal bruto. | Sí |
18. Dudas para el profesor (Fase 3)
| Duda | Lo que ya intenté |
|---|---|
| No aplica | No aplica |
19. Reflexión final
¿Qué aprendí con esta práctica?
La importancia de la programación modular, la validación de entradas de usuario y la verificación mediante casos de prueba estructurados.
Ahora que terminé, ¿qué cambiaría de mi proceso?
Planificar los casos de prueba antes de escribir el código base.
¿Qué fue lo más difícil y cómo lo resolví?
Asegurar el manejo correcto de tipos decimales en las operaciones de porcentaje, resuelto mediante el uso explícito de double y divisiones flotantes.
¿Qué pregunta me quedó sin responder?
Ninguna.
Comparado con las prácticas anteriores, donde todo estaba en main(), ¿dividir el programa en módulos me facilitó o me complicó el trabajo? ¿Por qué?
Facilitó el trabajo porque permitió aislar responsabilidades, simplificar la corrección de errores y mantener el código ordenado.
¿Cómo encontré el error de calcularDescuento? ¿Lo habría encontrado si solo hubiera probado sin descuento?
Mediante pruebas unitarias con valores distintos de cero. No se habría detectado probando únicamente con un descuento del 0%.
20. Commits (Fase 5)
¿Cuántos commits hice durante la práctica? 4
Si hice menos de 3, ¿por qué?
No aplica.
21. Lista de verificación antes de entregar (Fase 5)
 * [x] Llené las secciones 1 a 20 (no quedan _____; escribí No aplica donde corresponde)
 * [x] Completé el árbol de análisis descendente y la tabla de módulos
 * [x] Escribí en RECETA.md la receta de main y la de cada módulo, antes de programar
 * [x] Cada bloque de main.cpp tiene su comentario // Paso N, de acuerdo con mi receta
 * [x] Corregí el error de calcularDescuento y documenté cómo lo encontré
 * [x] Hice los Experimentos A y B y dejé el código correcto al terminar
 * [x] Mi ticket se ve alineado y termina con la línea de agradecimiento o firma leída
 * [x] Justifiqué dónde definí la constante o estructura del ticket
 * [x] Escribí funciones auxiliares y volví a correr todas las pruebas
 * [x] Hice al menos uno de los retos y lo documenté
 * [x] No queda ninguna salida [DEBUG] activa
 * [x] Mi programa compila sin advertencias
 * [x] Probé todos los casos de la tabla
 * [x] Revisé los principios de calidad de mi programa
 * [x] No modifiqué utilerias.h
 * [x] Tengo al menos 3 commits con mensajes claros (o justifiqué por qué no)
 * [x] Hice git push y verifiqué mi fork en GitHub
 * [x] Mi fork se llama ulsa_ime_1_dp_ticket_compra, mis módulos están en include/ticket.h y mi programa principal en src/main.cpp
 * [x] Entregué el enlace de mi fork en Classroom