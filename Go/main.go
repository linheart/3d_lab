package main

import (
	"fmt"
	"my_project/hash_table"
	"my_project/serialization"
)

func main() {
	ht := hash_table.NewHT()
	ht.Set("key1", "First")
	ht.Set("key2", "Second")
	ht.Set("key3", "Third")

	fmt.Println("Binary serialization")
	if err := serialization.SerializeBinary(ht, "data.bin"); err != nil {
		fmt.Println("Error during binary serialization:", err)
	}
	
	deserializedHT := hash_table.NewHT()
	if err := serialization.DeserializeBinary(deserializedHT, "data.bin"); err != nil {
		fmt.Println("Error during binary deserialization:", err)
	}

	fmt.Println("key1:", deserializedHT.Get("key1"))
	fmt.Println("key2:", deserializedHT.Get("key2"))
	fmt.Println("key3:", deserializedHT.Get("key3"))

	// Текстовая сериализация
	if err := serialization.SerializeText(ht, "data.txt"); err != nil {
		fmt.Println("Error during text serialization:", err)
	}

	// Текстовая десериализация
	deserializedTextHT := hash_table.NewHT()
	if err := serialization.DeserializeText(deserializedTextHT, "data.txt"); err != nil {
		fmt.Println("Error during text deserialization:", err)
	}

	fmt.Println("Text Deserialization:")
	fmt.Println("key1:", deserializedTextHT.Get("key1"))
	fmt.Println("key2:", deserializedTextHT.Get("key2"))
	fmt.Println("key3:", deserializedTextHT.Get("key3"))
}
