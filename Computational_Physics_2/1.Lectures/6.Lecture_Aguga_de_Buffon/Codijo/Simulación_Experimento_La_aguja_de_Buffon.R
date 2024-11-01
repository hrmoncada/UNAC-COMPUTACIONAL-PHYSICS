# https://www.mycompiler.io/view/Dz51U2HIxnn
# Simulación Experimento La aguja de Buffon
# Parámetros
L <- 1 # Longitud de la aguja
W <- 2 # Ancho de las tiras
N <- 10000 # Número de lanzamientos

# Función para determinar si la aguja cruza una línea
cruza_linea <- function(x, y, theta) {
  y + L/2 * abs(sin(theta)) >= W * floor(y/W) + W | 
  y - L/2 * abs(sin(theta)) <= W * floor(y/W)
}

# Simulación del experimento
set.seed(123) # Semilla para reproducibilidad
theta <- runif(N, 0, pi) # Ángulo de la aguja
x <- runif(N, 0, W/2) # Posición x de la aguja
y <- runif(N, 0, W) # Posición y de la aguja
M <- sum(sapply(1:N, function(i) cruza_linea(x[i], y[i], theta[i]))) # Número de cruces

# Estimación de pi
pi_estimado <- 2  * N / (M * W)
pi_estimado

