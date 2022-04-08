package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
	"net/url"
)

type bodyResponse struct {
	BATCH []string `json:"batch"`
}

func main() {
	structAddress := getEntites()
	callLocationAPI(structAddress.ADDRESS)
}

func callLocationAPI(queryList []string) {
	baseURL, _ := url.Parse("http://api.positionstack.com")

	baseURL.Path += "v1/forward"
	var resultList []string
	// iterate over the list of addresses
	for _, query := range queryList {
		params := url.Values{}
		// Access Key
		params.Add("access_key", "be17ae76cbd648c57ccafa9adfeb00c6")
		// Query
		params.Add("query", query)
		params.Add("fields", "results.latitude,results.longitude")
		// Optional parameters
		params.Add("country", "BR")
		params.Add("region", "Nova Friburgo")
		params.Add("limit", "1")

		baseURL.RawQuery = params.Encode()
		fmt.Println(baseURL.String())

		req, _ := http.NewRequest("GET", baseURL.String(), nil)

		res, _ := http.DefaultClient.Do(req)
		if res.StatusCode != 200 {

			fmt.Println("Error: ", res.StatusCode)
		}

		defer res.Body.Close()

		bodyRes, _ := ioutil.ReadAll(res.Body)

		fmt.Println(string(bodyRes))
		// convert bodyRes byte to json

		resultList = append(resultList, string(bodyRes))

	}
	// create a byte array from the resultList
	var bodyResponse bodyResponse
	bodyResponse.BATCH = resultList
	// marshal the bodyResponse to json
	jsonBody, _ := json.Marshal(bodyResponse)
	// write the json to a file
	ioutil.WriteFile("result.json", jsonBody, 0644)
}
