import React,{Component} from "react";
import App from "./App";
import ReactDOM from "react-dom";
import "./styles.css"
class Calculator extends Component{
        render(){
                return(
                        <App/>
                )
        }
}
ReactDOM.render(<Calculator/>,document.getElementById("root"));