#' The application server-side
#' 
#' @param input,output,session Internal parameters for {shiny}. 
#'     DO NOT REMOVE.
#' @import shiny
#' @noRd
app_server <- function( input, output, session ) {
  # List the first level callModules here
  output$penguine <- renderImage({
    return(list(src = "/root/Documents/shirpi/example_003/golemshiny/R/palmer_penguins_plot.png",
    
                width = 800,
                height = 600
                )
    )
  }, deleteFile = FALSE)

}
