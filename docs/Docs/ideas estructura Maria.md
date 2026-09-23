🌿 Sinfonía Biótica – Versión 2
Documento de Diseño / Storyboard – Versión Lineal Guiada
1. Estructura General
Experiencia en VR basada en un recorrido lineal.
El jugador avanza a lo largo de un camino que estructura la secuencia de eventos visuales y sonoros.
Puede detenerse y explorar libremente los paisajes laterales, pero el foco principal sigue siendo el viaje hacia adelante.
Se trabajará con 6 Gaussian Splats diferentes (árboles, hongos, etc.) que se revelarán progresivamente a lo largo del recorrido.
Se mantiene la lógica de la versión anterior en cuanto a colliders y triggers de proximidad para activar eventos sonoros y musicales. (La pregunta ahora es cuándo)
2. Sistema de Guiado y Revelado
2.1. Camino de Partículas
Un camino de partículas marca la dirección principal.
La guía puede desaparecer temporalmente para favorecer la contemplación.
Si el jugador permanece quieto demasiado tiempo, reaparece como recordatorio de hacia dónde avanzar.
2.2. Bichitos / Centinelas Sonoros
Pequeñas criaturas con emitters 3D aparecen en puntos clave, emitiendo sonidos espacializados que guían de forma no verbal.
Actúan como marcadores acústico-visuales naturales.
Pueden activarse automáticamente al llegar a ciertas zonas o cuando el jugador permanece inactivo.
2.3. Apariciones Laterales
A medida que el jugador avanza, aparecen paisajes laterales de forma gradual, como si se estuviese dando un paseo por el bosque o montando bici, y se observaran escenas apareciendo a lo lejos.
Estos paisajes corresponden a los distintos splats (bosques, fungis, otros ecosistemas), que al principio se presentan como “pinceladas parciales” antes de llegar a su versión completa más adelante en el recorrido. (no sé si se pueda separar una parte del splat o si tenemos fotografías de elementos más pequeños que componen un ecosistema)
El jugador puede detenerse y explorar brevemente estos paisajes laterales, pero el diseño mantiene el foco principal en el avance.
En algún punto podría la aparicion no ser lateral pero en frente de tu como para indicar que estás atravesando algo.
La idea no es "No ser partícipe" de la co-creación con el ecosistema ni mirarlo siempre desde lejos, igual puede ser que lo miras de lejos con respeto pero si vas hasta allí dentro del ecosistema pasa algo interesante a nivel sonoro-visual
2.4. Revelado Progresivo del Mundo
El entorno se va llenando progresivamente conforme se camina.
Al principio solo se muestran elementos esenciales y de background que de por sí deberían ser contemplativos o interesantes (camino, bichitos, pequeños fragmentos); con el tiempo se van añadiendo capas visuales y sonoras hasta llegar a una imagen final más completa al final del recorrido.
El revelado puede controlarse mediante activación por zonas, máscaras o la carga secuencial de chunks de splats.

2.5 Ritmo de la Experiencia
Avanzar → activa transformaciones y eventos.
Pausar → permite contemplar, en un estado más “suspendido”.
Se alternan momentos de progresión y contemplación sin necesidad de texto ni instrucciones directas.

3. Checkpoints Musicales (Theremin)
A lo largo del recorrido habrá puntos de checkpoint en los que el jugador podrá activar mecánicas musicales interactivas (tipo theremin con los controladores VR).
Al llegar a un checkpoint:
Se mostrará una cue visual muy clara (partículas concentradas, luz, diagrama flotante o incluso texto breve).
La música general bajará en intensidad para dejar espacio a la improvisación del jugador.
Durante esta sección, el jugador “solea” libremente — puede interactuar con el entorno y generar sonidos/melodías con gestos.
Al interactuar correctamente, la música vuelve a subir progresivamente, reforzando positivamente la acción.
Aún no sé en dónde poner narrativamente estos checkpoints
4. Sistema Sonoro Interactivo (FMOD)
4.1. Principio
El sonido guía y estructura la experiencia:
La música por capas reacciona al movimiento (avance, pausa, interacción).
Emitters 3D (camino / bichitos) refuerzan direcciones espaciales.
Checkpoints modifican la mezcla musical para abrir espacios interactivos.
4.2. Estados Musicales (Ejemplo de Lógica)
Movimiento(player) constante: suma progresiva de capas musicales y ambientales.
Pausa breve: mantiene la base, estado suspendido.
Inactividad prolongada: se reducen capas → sensación de quietud / suspensión.
Estos cambios de capas funcionan como un feedback no verbal para incentivar el movimiento.