import express from "express"
import cors from "cors";

const app = express()

app.use(express.json())
app.use(cors());

app.get("/", (req, res) => {
    const responseObj = {nome: "Vitor", id: "505044890as"}
    res.json(responseObj);
})

app.post("/", (req, res) => {
    console.log(req.body);
    const responseObj = {nome: req.body.nome, id: "505044890as"}
    res.json(responseObj);
})

app.listen(5001, () => console.log("Running server"))

