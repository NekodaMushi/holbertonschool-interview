import requests


def count_words(subreddit, word_list, after="", word_count={}):
    if after is None:
        sorted_words = sorted(word_count.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_words:
            if count > 0:
                print(f"{word}: {count}")
        return

    url = f"https://www.reddit.com/r/{subreddit}/hot.json?after={after}"
    headers = {"User-Agent": "your-app-name"}

    response = requests.get(url, headers=headers)
    if response.status_code != 200:
        return

    data = response.json()
    articles = data["data"]["children"]

    for article in articles:
        title = article["data"]["title"].lower()
        for word in word_list:
            word_l = word.lower()
            count = (
                title.count(f" {word_l} ")
                + title.count(f" {word_l}.")
                + title.count(f" {word_l},")
            )
            word_count[word_l] = word_count.get(word_l, 0) + count

    count_words(subreddit, word_list, data["data"]["after"], word_count)


if __name__ == "__main__":
    count_words("programming", ["python", "java", "javascript"])
