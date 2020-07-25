library(shiny)
library(shinydashboard)

shinyServer(
  
  function(input, output) {
    output$histogram <- renderPlot(
      {
        hist(faithful$eruptions, breaks = input$bins)
      }
    )
    
  }
)