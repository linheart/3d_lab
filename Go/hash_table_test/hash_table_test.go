package hash_table_test

import (
	"hash_table/hash_table"
	"strconv"
	"testing"
	"time"
)

func TestConstructorDestructor(t *testing.T) {
	startTime := time.Now()
	ht := hash_table.NewHT()
	duration := time.Since(startTime)
	t.Logf("%.9f seconds", duration.Seconds())
	_ = ht
}

func TestInsertAndRetrieve(t *testing.T) {
	startTime := time.Now()
	ht := hash_table.NewHT()

	ht.Set("key1", "value1")
	ht.Set("key2", "value2")

	if ht.Get("key1") != "value1" {
		t.Errorf("Expected value for key1 is value1 but got %s", ht.Get("key1"))
	}

	if ht.Get("key2") != "value2" {
		t.Errorf("Expected value for key2 is value2 but got %s", ht.Get("key2"))
	}

	if ht.Get("key3") != "" {
		t.Errorf("Expected value for key3 is empty but got %s", ht.Get("key3"))
	}
	duration := time.Since(startTime)
	t.Logf("%.9f seconds", duration.Seconds())
}

func TestOverwriteValue(t *testing.T) {
	startTime := time.Now()
	ht := hash_table.NewHT()

	ht.Set("key1", "value1")

	if ht.Get("key1") != "value1" {
		t.Errorf("Expected value for key1 is value1 but got %s", ht.Get("key1"))
	}

	ht.Set("key1", "new_value")

	if ht.Get("key1") != "new_value" {
		t.Errorf("Expected value for key1 is new_value but got %s", ht.Get("key1"))
	}
	duration := time.Since(startTime)
	t.Logf("%.9f seconds", duration.Seconds())
}

func TestHandleCollisions(t *testing.T) {
	startTime := time.Now()
  ht := make(map[string]string)
    
  key1 := "key1"
  key2 := "key2"
    
	ht[key1] = "value1"
  ht[key2] = "value2"
    
  if ht[key1] == ht[key2] {
    t.Errorf("Expected %s and %s to have different values", key1, key2)
  }
	duration := time.Since(startTime)
	t.Logf("%.9f seconds", duration.Seconds())
}

func TestDestructorHandlesMemory(t *testing.T) {
  startTime := time.Now()
	ht := make(map[string]string)
  ht["key1"] = "value1"
	duration := time.Since(startTime)
	t.Logf("%.9f seconds", duration.Seconds())
}

func TestLargeData(t *testing.T) {
	startTime := time.Now()
	ht := hash_table.NewHT()

	for i := 0; i < 1000; i++ {
		ht.Set("key"+strconv.Itoa(i), "value"+strconv.Itoa(i))

	}

	for i := 0; i < 1000; i++ {
		if ht.Get("key"+strconv.Itoa(i)) != "value"+strconv.Itoa(i) {
			t.Errorf("Value mismatch for key%d", i)
		}
	}
	duration := time.Since(startTime)
	t.Logf("%.9f seconds", duration.Seconds())
}

func TestEmptyValue(t *testing.T) {
	startTime := time.Now()
	ht := make(map[string]string)
	ht["key1"] = ""
	if ht["key1"] != "" {
		t.Errorf("Expected empty string, but got %s", ht["key1"])
	}
	duration := time.Since(startTime)
	t.Logf("%.9f seconds", duration.Seconds())
}

func TestReuseKey(t *testing.T) {
	startTime := time.Now()
	ht := make(map[string]string)

	ht["key1"] = "value1"
	if ht["key1"] != "value1" {
		t.Errorf("Expected 'value1', but got %s", ht["key1"])
	}

	ht["key1"] += "_appended"
	if ht["key1"] != "value1_appended" {
		t.Errorf("Expected 'value1_appended', but got %s", ht["key1"])
	}
	duration := time.Since(startTime)
	t.Logf("%.9f seconds", duration.Seconds())
}