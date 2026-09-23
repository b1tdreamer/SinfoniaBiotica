# Sinfonía Biótica: cuando humanos y árboles co-crean en realidad virtual

¿Puede la tecnología servir para reconectar con la naturaleza en lugar de alejarnos de ella? Esta paradoja constituye el punto de partida de **Sinfonía Biótica**, un proyecto que convierte la realidad virtual en un puente sensorial hacia el mundo vegetal, haciendo audible lo que nuestros sentidos no alcanzan a percibir. En un momento marcado por el colapso climático y la distancia creciente entre lo urbano y lo natural, el arte digital puede ofrecer no solo escapismo, sino nuevas formas de relación con organismos no humanos.

## Un ecosistema creativo interespecie

Sinfonía Biótica es un ecosistema creativo interespecie: una experiencia inmersiva de realidad virtual interactiva en la que humanos y plantas colaboran para generar una pieza audiovisual única. Cada organismo digitalizado —árboles emblemáticos de España y Portugal— actúa como un instrumento dentro de esta sinfonía. Sus impulsos eléctricos, registrados durante horas, se traducen en melodías, ritmos y texturas sonoras; el movimiento y la voz del participante modifican el paisaje en tiempo real. El resultado es una obra irrepetible, cuya forma depende de la actividad bioeléctrica de cada planta, la hora del día y la intensidad de los gestos de quien porta el headset.

La barrera entre espectador y creador desaparece. No se trata de contemplar una escena predefinida, sino de co-crear con encinas, fresnos, bosques de laurisilva o secuoyas digitalizadas. Estas especies —la encina solitaria de la dehesa salmantina, la fresna de Sancti-Spíritus, la laurisilva de Fanal (Madeira) o las secuoyas gigantes de Buçaco— han sido capturadas mediante técnicas de *gaussian splatting*, generando nubes de puntos fotorrealistas que conservan la atmósfera y la morfología de los espacios originales. Sus cuerpos virtuales se alteran en tiempo real según los datos previamente registrados y las acciones del usuario. La obra se genera mediante la interacción de tres agentes creativos: los árboles (a través de sus impulsos eléctricos), el usuario (mediante movimientos, voz y exploración) y el sistema que traduce, interpreta y fusiona ambas entradas.

## Tecnología como traductor: biodata, VR y sonificación

Para capturar la «voz» de las plantas, el proyecto utiliza dispositivos de **biodata**: hardware open source basado en Arduino ESP-32 que amplifica las señales eléctricas en el rango de microvoltios y las variables medioambientales y las convierte en datos MIDI. Esta actividad bioeléctrica está ligada a procesos como la fotosíntesis, el transporte de nutrientes y la respuesta a estímulos ambientales —luz, tacto, temperatura—, que la ciencia vegetal investiga desde hace décadas. El biodata, originalmente desarrollado por Sam Cusumano y adaptado por el equipo de Sinfonía Biótica, permite traducir esos impulsos en parámetros sonoros y visuales accesibles a la percepción humana. Los dispositivos se fabrican con impresoras 3D y su documentación es pública, de modo que cualquier persona interesada puede construir su propio sensor y contribuir a la red de árboles monitorizados. Durante 2024 y 2025 se han registrado más de treinta ejemplares en distintas localizaciones.

La digitalización de los espacios combina fotogrametría y *gaussian splatting*, una técnica reciente que produce nubes de puntos con calidad fotorrealista a partir de fotografías. Cada punto contiene información de posición, color y opacidad, permitiendo un renderizado en tiempo real que supera en realismo a la fotogrametría tradicional y resulta más eficiente que las mallas 3D convencionales para entornos VR. La captura se realiza con dron DJI Mini 4 Pro y cámara Osmo Pocket 3; el procesamiento genera millones de pinceladas que se integran en Unreal Engine mediante plugins especializados. Sinfonía Biótica es uno de los primeros proyectos artísticos españoles en aplicar esta tecnología en entornos inmersivos, explorando un terreno aún experimental dentro del panorama de la creación digital.

El diseño sonoro, a cargo de las compositoras **María Castro**, **Laura Zapata** y **Pedro Fraguela**, asigna a cada organismo un instrumento virtual propio diseñado según sus características ecosistémicas. Los impulsos eléctricos se convierten en notas MIDI que activan síntesis adaptativa; el paisaje sonoro ambiente (grabaciones de campo), las melodías generadas por las plantas y los sonidos provocados por los movimientos del usuario se superponen en capas no lineales. Cada movimiento musical utiliza escalas y modos únicos inspirados en el ecosistema que representa. La música nunca suena igual dos veces. La documentación técnica está disponible en [sinfoniabiotica.xyz/the-tecnology/](https://sinfoniabiotica.xyz/the-tecnology/).

## Estructura de la experiencia

La experiencia se divide en dos partes. La primera, introductoria, es una pieza de unos siete minutos pensada para festivales y encuentros en los que una serie de seres nos acompañan en el descubrimiento de capas de realidad superpuestas a la que conocemos: organismos que se comunican entre sí, comparten nutrientes y, en definitiva, colaboran para desarrollarse y crear más vida, más biomasa, más biodiversidad. Tras esta introducción, accedemos a un espacio abierto desde el que podemos visitar los diferentes ecosistemas recopilados —la encina solitaria de la dehesa salmantina, emblema de resistencia en la península ibérica; la fresna de Sancti-Spíritus; el bosque de laurisilva de Fanal (Madeira), relicto del Terciario y Patrimonio de la Humanidad UNESCO; las secuoyas gigantes de la Mata Nacional do Buçaco, monumento nacional portugués; pinares de montaña, choperas de ribera y otros paisajes ibéricos—, explorando y co-creando con cada uno de ellos.

## Ecología, patrimonio y cambio climático

Sinfonía Biótica no es solo una pieza artística; es también valorización del patrimonio natural ibérico y documentación digital de ecosistemas emblemáticos. Los árboles digitalizados son testigos y víctimas del cambio climático: la laurisilva de Madeira, sensible a cambios de humedad; las encinas ibéricas amenazadas por sequías extremas y desertificación; los bosques de ribera alterados por los ciclos hídricos; los pinos de montaña expuestos a nuevas condiciones. Al hacerlos «experimentables» en primera persona, el proyecto genera empatía y conciencia sobre la urgencia de su protección, transformando la percepción de «recursos naturales» en la de «co-habitantes del planeta» con agencia propia.

Los valores del proyecto se materializan en la práctica: código y hardware abiertos, documentación pública accesible, 50 % de los beneficios destinados a la plantación y cuidado del bosque de MolinoLab (que recupera un terreno degradado por prácticas ganaderas y agrícolas), y una plataforma de datos abiertos ([db.sinfoniabiotica.xyz](https://db.sinfoniabiotica.xyz)) que ofrece un mapa de registros, datos medioambientales y eléctricos, y, en desarrollo, una API para que otros creadores, artistas y científicos desarrollen instalaciones, estudios o herramientas a partir de la información recopilada. La apertura es explícitamente una estrategia de continuidad: el proyecto crece cuando más personas contribuyen con sus propios biodata o sus creaciones derivadas.

## Centinelas, talleres y datos en tiempo real

En 2025 hemos desarrollado otros proyectos electrónicos conectados con Sinfonía Biótica, los **Centinelas del bosque**, dispositivos interactivos que conectan con árboles específicos y traducen su actividad bioeléctrica en luz y sonido. Son objetos contemplativos que permiten seguir las «señales vitales» de un árbol desde casa, con un código QR que enlaza a los datos en tiempo real. Disponibles como kits DIY o preensamblados, se fabrican con impresión 3D, corte láser o fieltro, y pueden incorporar elementos orgánicos como corteza o ramas del propio árbol. Funcionan como vínculo emocional entre la persona y un organismo concreto, invitando a la contemplación y la conexión profunda con la naturaleza urbana o rural.

El biodata se ha ampliado con sensores de temperatura, humedad, iluminación calibrada, luz ultravioleta e índice de calidad del aire, gracias a la colaboración con la Escuela de Montes de la Universidad Politécnica de Madrid. Se almacenan datos crudos (desviación estándar, media, máximo, mínimo, umbral) con la resolución máxima permitida por los sensores, superando la conversión previa a MIDI de 127 valores. Las grabaciones de larga duración —y pronto el streaming en vivo desde árboles como el de MolinoLab o el de Nairobi (Myunbuni)— enriquecen la base de datos para futuros análisis con deep learning y correlaciones con variables ambientales.

Talleres y formaciones con la UC3M, Medialab Matadero, MolinoLab y el Festival InteractivasFest difunden estas prácticas; el proyecto ha sido presentado en Ars Electronica (2024 y 2025), BIME, RTVE, Castilla y León Televisión, CarneCruda y Cineteca Matadero, entre otros espacios, y forma parte de la red ACTS (Arte, Ciencia, Tecnología y Sociedad).

## Nuevas narrativas sobre la coexistencia

Sinfonía Biótica cuestiona el antropocentrismo al reconocer la agencia de seres no humanos y proponer una ética del cuidado basada en la comprensión y la empatía. La tecnología no sustituye el contacto con la naturaleza: actúa como interfaz que amplifica lo que de otro modo permanecería oculto, permitiendo imaginar futuros donde la creación digital sirve para reconectar, no para separar. En el cruce entre arte, ciencia y comunicación multimedia, proyectos como este abren vías para que creadores, educadores e instituciones exploren nuevas formas de relación con el entorno vivo.

La experiencia está disponible en acceso anticipado en [sinfoniabiotica.xyz](https://sinfoniabiotica.xyz), en Itch.io y en proceso de publicación en Steam. Invita a escuchar, crear y reconocerse como parte de una red de vida que trasciende especies y fronteras.

---

**Figura 1.** Captura de la experiencia de realidad virtual Sinfonía Biótica. Fuente: Sinfonía Biótica / MolinoLab.

**Figura 2.** Dispositivo biodata conectado a un árbol. Fuente: Sinfonía Biótica.

**Figura 3.** Árbol digitalizado mediante gaussian splatting. Fuente: Sinfonía Biótica.

---

### Sobre el autor

**Fernando Fernández** es artista interdisciplinar y tecnólogo que explora la comunicación interespecie a través del arte y la tecnología. Creador de Sinfonía Biótica, fundador de MolinoLab y mentor técnico en Medialab Matadero, su trabajo combina biosensores, digitalización 3D y experiencias inmersivas en tiempo real.

**Enlaces:** [sinfoniabiotica.xyz](https://sinfoniabiotica.xyz) | [molinolab.org](https://molinolab.org) | [b1tdreamer.xyz](https://b1tdreamer.xyz)

---

*Cita recomendada:* FERNÁNDEZ, Fernando. Sinfonía Biótica: cuando humanos y árboles co-crean en realidad virtual. *Mosaic* [en línea], [fecha de publicación], no. [número]. ISSN: 1696-3296.
