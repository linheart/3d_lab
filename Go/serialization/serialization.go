package serialization

import (
	"bufio"
	"encoding/binary"
	"errors"
	"io"
	"my_project/hash_table"
	"os"
	"strings"
)

// SerializeBinary serializes the hash table into a binary file.
func SerializeBinary(ht *hash_table.HT, filename string) error {
	file, err := os.Create(filename)
	if err != nil {
		return err
	}
	defer file.Close()

	writer := bufio.NewWriter(file)
	for _, head := range ht.Node {
		current := head
		for current != nil {
			keySize := uint32(len(current.Key))
			valueSize := uint32(len(current.Value))

			if err := binary.Write(writer, binary.LittleEndian, keySize); err != nil {
				return err
			}
			if _, err := writer.WriteString(current.Key); err != nil {
				return err
			}
			if err := binary.Write(writer, binary.LittleEndian, valueSize); err != nil {
				return err
			}
			if _, err := writer.WriteString(current.Value); err != nil {
				return err
			}

			current = current.Next
		}
	}
	return writer.Flush()
}

// DeserializeBinary deserializes the binary file into the hash table.
func DeserializeBinary(ht *hash_table.HT, filename string) error {
	file, err := os.Open(filename)
	if err != nil {
		return err
	}
	defer file.Close()

	reader := bufio.NewReader(file)
	for {
		var keySize uint32
		if err := binary.Read(reader, binary.LittleEndian, &keySize); err != nil {
			if errors.Is(err, io.EOF) {
				break
			}
			return err
		}

		key := make([]byte, keySize)
		if _, err := reader.Read(key); err != nil {
			return err
		}

		var valueSize uint32
		if err := binary.Read(reader, binary.LittleEndian, &valueSize); err != nil {
			return err
		}

		value := make([]byte, valueSize)
		if _, err := reader.Read(value); err != nil {
			return err
		}

		ht.Set(string(key), string(value))
	}
	return nil
}

// SerializeText serializes the hash table into a text file.
func SerializeText(ht *hash_table.HT, filename string) error {
	file, err := os.Create(filename)
	if err != nil {
		return err
	}
	defer file.Close()

	writer := bufio.NewWriter(file)
	for _, head := range ht.Node {
		current := head
		for current != nil {
			line := current.Key + "=" + current.Value + "\n"
			if _, err := writer.WriteString(line); err != nil {
				return err
			}
			current = current.Next
		}
	}
	return writer.Flush()
}

// DeserializeText deserializes the text file into the hash table.
func DeserializeText(ht *hash_table.HT, filename string) error {
	file, err := os.Open(filename)
	if err != nil {
		return err
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.SplitN(line, "=", 2)
		if len(parts) != 2 {
			return errors.New("invalid format in text file")
		}
		ht.Set(parts[0], parts[1])
	}
	return scanner.Err()
}
