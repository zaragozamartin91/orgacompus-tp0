# orgacompus-tp0
TP0 de orga de compus 

Compilar:
    make

Correr:
    ./app.exe [OPCIONES]

OPCIONES:
    -r, o --resolution, permite cambiar la resolución de la imagen generada. El valor por defecto será de 640x480 puntos.
    -c, o --center, para especificar las coordenadas correspondientes al punto central de la porción del plano complejo dibujada, expresado en forma binómica (i.e. a+bi). Por defecto usaremos 0+0i.
    -w, o --width, especifica el ancho de la región del plano complejo que estamos por dibujar. Valor por defecto: 2.
    -H, o --height, sirve, en forma similar, para especificar el alto del rectángulo a dibujar. Valor por defecto: 2.
    -s, o --seed, para configurar el valor complejo de la semilla usada para generar el fractal. Valor por defecto: -0.726895347709114071439+0.188887129043845954792i.
    -o, o --output, permite colocar la imagen de salida, (en formato PGM [6]) en el archivo pasado como argumento; o por salida estándar -cout- si el argumento es “-”.
