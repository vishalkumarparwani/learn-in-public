# brokers like RabbitMQ, Kafka and SQS deliver messages 
# at least once.The same message can arrive twice after 
# a retry, a timeout, or a consumer crash before the ack
#-------------------------------------------------------

class IdempotentConsumer:
    def __init__(self):
        self.processed_ids = set()
        self.balance = 0

    def handle(self, message):
        message_id = message["id"]

        if message_id in self.processed_ids:
            print(f"Message {message_id} has already been processed. Skipping")
            return False
        self.balance += message["amount"]
        self.processed_ids.add(message_id)
        print(f"Processed message {message_id}")
        print(f"New balance: {self.balance}")
        return True

if __name__ == "__main__":
    consumer = IdempotentConsumer()
    messages = [
        {"id": 1, "amount": 100},
        {"id": 2, "amount": 200},
        {"id": 1, "amount": 100},  #dup id
        {"id": 3, "amount": 300},
        {"id": 2, "amount": 200},  #dup id
    ]
    results = []

    for message in messages:
        results.append(consumer. handle(message))
    assert results == [True, True, False, True, False]
    assert consumer.balance == 600

    bad_message = {"id": 4}
    try:
        consumer.handle(bad_message)
    except KeyError:
        pass
    assert "4" not in consumer.processed_ids
    print("All tests passed")