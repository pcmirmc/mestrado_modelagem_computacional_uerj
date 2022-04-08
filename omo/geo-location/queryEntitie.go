package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"os"
)

type AddressJson struct {
	ADDRESS []string `json:"address"`
}

func getEntites() AddressJson {
	// read address.json as a struct
	var addressJson AddressJson
	jsonFile, err := os.Open("./address.json")
	if err != nil {
		fmt.Println(err)
	}
	defer jsonFile.Close()
	byteValue, _ := ioutil.ReadAll(jsonFile)
	json.Unmarshal(byteValue, &addressJson)

	return addressJson

}
