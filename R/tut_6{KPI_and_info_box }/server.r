library(shiny)
library(shinydashboard)

shinyServer(
  
  function(input, output) {
    output$histogram <- renderPlot({
        hist(faithful$eruptions, breaks = input$bins)
      })
    
    output$msgOutput <- renderMenu({
      msgs<-apply(read.csv("noti.csv"),1,function(row){
        messageItem(from = row[["From"]],message = row[["message"]])
      })
      dropdownMenu(type = "messages", .list = msgs)
    })
    
    output$approvedSales <- renderInfoBox({
      infoBox("Approval sales","100")
    })
 
  })