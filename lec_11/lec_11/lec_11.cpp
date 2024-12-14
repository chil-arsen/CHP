import requests
import random
import time

BASE_URL = "https://new-api.example.com"
HEADERS = { "Accept": "application/json" }

def get_filtered_posts() :
    """Fetch posts and filter based on specific conditions."""
    response = requests.get(f"{BASE_URL}/posts", headers = HEADERS)
    if response.status_code == 200 :
        posts = response.json()
        filtered = [
            post for post in posts
                if len(post['title'].split()) <= 6 and post['body'].count('\n') <= 3
        ]
        print(f"Filtered {len(filtered)} posts:")
        for post in filtered :
print(f"ID: {post['id']}, Title: {post['title']}")
return filtered
                else:
            print(f"Failed to fetch posts. Status code: {response.status_code}")
                return[]

                def create_post() :
                """Create a new post."""
                title = input("Enter the title: ")
                body = input("Enter the body: ")
                payload = { "title": title, "body" : body, "userId" : 1 }
                response = requests.post(f"{BASE_URL}/posts", json = payload, headers = HEADERS)
                if response.status_code == 201:
            print("Post created successfully!")
                return response.json()
                else:
            print(f"Failed to create post. Status code: {response.status_code}")
                return None

                def update_post() :
                """Update an existing post."""
                post_id = input("Enter the post ID to update: ")
                title = input("Enter the new title: ")
                body = input("Enter the new body: ")
                payload = { "title": title, "body" : body, "userId" : 1 }
                response = requests.put(f"{BASE_URL}/posts/{post_id}", json = payload, headers = HEADERS)
                if response.status_code == 200:
            print("Post updated successfully!")
                return response.json()
                else:
            print(f"Failed to update post. Status code: {response.status_code}")
                return None

                def delete_post() :
                """Delete a post."""
                post_id = input("Enter the post ID to delete: ")
                response = requests.delete(f"{BASE_URL}/posts/{post_id}", headers = HEADERS)
                if response.status_code == 200 :
                    print(f"Post {post_id} deleted successfully!")
                    return True
                else:
            print(f"Failed to delete post. Status code: {response.status_code}")
                return False

                def main() :
                """Simple menu to perform CRUD operations."""
                while True :
                    print("\n1. Get filtered posts\n2. Create a post\n3. Update a post\n4. Delete a post\n5. Exit")
                    choice = input("Choose an option: ")
                    if choice == "1" :
                        time.sleep(random.uniform(1, 2))
                        get_filtered_posts()
                        elif choice == "2" :
                        time.sleep(random.uniform(1, 2))
                        create_post()
                        elif choice == "3" :
                        time.sleep(random.uniform(1, 2))
                        update_post()
                        elif choice == "4" :
                        time.sleep(random.uniform(1, 2))
                        delete_post()
                        elif choice == "5" :
                        print("Exiting program.")
                        break
                    else:
            print("Invalid choice. Try again.")

                if __name__ == "__main__" :
                    main()
